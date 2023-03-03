#include "mainwindow.h"
#include "opencv2/core/hal/interface.h"
#include "ui_mainwindow.h"
#include<QImage>
#include<QDialog>
#include<QSpinBox>
#include<QFont>
#include<QDoubleSpinBox>
#include<QCheckBox>
#include<QButtonGroup>
#include<QRadioButton>
#include <QDialogButtonBox>
#include<QScrollArea>
#include<QScrollBar>
#include <QFormLayout>
#include <QLineEdit>
#include <QTextEdit>
#include<stack>


cv::Mat img,uimg;
QString fname;
MainWindow ::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::unreadError(){
    QMessageBox::information(
        this,
        tr("エラー"),
        tr("ファイルが読み込まれていません") );
}

void MainWindow::unreadableError(){
    QMessageBox::information(
        this,
        tr("エラー"),
        tr("ファイルを読み込めませんでした") );
}

void MainWindow::unselectMethodError(){
    QMessageBox::information(
        this,
        tr("エラー"),
        tr("手法を選択してください") );
}

QPixmap MainWindow::opcvToQpixmap(cv::Mat in){
    int channel = in.channels();
    if(in.type() == 5){
        in.convertTo(in,CV_8U,255);
    }

    if(channel == 3){
        cv::Mat dst;
        cv::cvtColor(in,dst,cv::COLOR_BGR2RGB);

        QImage iImg( (const unsigned char*) (dst.data),
                     dst.cols, dst.rows,
                     in.step,
                     QImage::Format_RGB888);
        QPixmap oImg(QPixmap::fromImage(iImg));
        return oImg;
    }else{
        QImage iImg( (const unsigned char*) (in.data),
                     in.cols, in.rows,
                     in.step,
                     QImage::Format_Indexed8);
        QPixmap oImg(QPixmap::fromImage(iImg));
        return oImg;
    }


}

void MainWindow::setPixmapImage(QPixmap inImg){
    int w = inImg.width();
    int h = inImg.height();
    ui->sizeLabel->setText("幅×高さ " + QString::number(w) + "×" + QString::number(h));

    ui->Image->setMinimumSize(w,h);
    ui->scrollArea->widget()->resize(w,h);
    ui->Image->resize(ui->scrollArea->widget()->width(),ui->scrollArea->widget()->height());
    ui->Image->setPixmap(inImg.scaled(w,h,Qt::KeepAspectRatio));
    ui->spinBox_2->setValue(100);
}

int MainWindow::mapclearmessage()
{
    QLabel *message = new QLabel;
    message->setText("現在表示されている画像は消去されますがよろしいですか？");
    QDialogButtonBox *buttonBox = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
    );

    QVBoxLayout *vb = new QVBoxLayout();
    vb->addWidget(message);
    vb->addWidget(buttonBox);

    QDialog *dialog = new QDialog(this);
    dialog->setModal(true);
    dialog->setMinimumSize(150,150);
    dialog->setWindowTitle(tr("実行確認"));
    dialog->setLayout(vb);

    connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

    int check = dialog->exec();

    return check;

}

void MainWindow::on_openButton_released()
{
    QString selFilter1;
    QString fileName1 = QFileDialog::getOpenFileName(this,
                                                    tr("ファイルを開く"),
                                                    "C:",
                                                    tr("JPEG(*.jpeg *.jpg *.jpe);;PNG(*.png);;TIFF(*.tif *.tiff);;Portable Image Format(*.pbm *.pgm *.ppm);;Windows Bitmaps(*.bmp)"),
                                                    &selFilter1,
                                                    QFileDialog::DontUseCustomDirectoryIcons);
    if (!fileName1.isEmpty()) {
        fname = fileName1;
        QImage lImg;
        lImg.load(fileName1);
        QPixmap img1(QPixmap::fromImage(lImg));
        QImage Img = lImg.convertToFormat(QImage::Format_RGB888);
        cv::Mat limg(Img.height(),Img.width(),CV_8UC3,(void *)Img.constBits(),Img.bytesPerLine());
        cv::cvtColor(limg,limg,cv::COLOR_RGB2BGR);


        img = limg.clone();
        uimg = limg.clone();
        if(img.empty()){
            unreadableError();
        }else{

            ui->file->setText("保存場所 "+fileName1);
            setPixmapImage(img1);
            ui->doname->setText("");
        }
    }


}

void MainWindow::on_saveButton_released()
{
    cv::Mat save = uimg.clone();

    QPixmap saveImg = opcvToQpixmap(save);

    if(saveImg.isNull()){
        unreadError();
    }else{
        QString selFilter;
        QString fileName = QFileDialog::getSaveFileName(
            this,
            tr("名前を付けて保存"),
            "C:",
            tr("JPEG(*.jpeg *.jpg *.jpe);;PNG(*.png);;TIFF(*.tif *.tiff);;Portable Image Format(*.pbm *.pgm *.ppm);;Windows Bitmaps(*.bmp)"),
            &selFilter,
            QFileDialog::DontUseCustomDirectoryIcons
        );
        if (!fileName.isEmpty()) {
            saveImg.save(fileName);

            ui->sizeLabel->setText("幅×高さ " + QString::number(saveImg.width()) + "×" + QString::number(saveImg.height()));
            ui->file->setText("保存場所 "+fileName);
        }
    }
}

void MainWindow::on_kakudai_released()
{
    if(!uimg.empty()){
        cv::Mat Src = uimg.clone();
        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
        );
        buttonBox->button(QDialogButtonBox::Ok)->setText(tr("実行"));
        buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("キャンセル"));

        QLabel *vertLabel = new QLabel;
        vertLabel->setText("高さ");
        QLabel *horiLabel = new QLabel;
        horiLabel->setText("幅");
        QLabel *label1 = new QLabel;
        label1->setText("倍");
        QLabel *label2 = new QLabel;
        label2->setText("倍");

        QRadioButton *nearest = new QRadioButton;
        nearest->setText("ニアレストネイバー");
        nearest->setChecked(true);
        QRadioButton *biliner = new QRadioButton;
        biliner->setText("バイリニア");
        QRadioButton *bicubic = new QRadioButton;
        bicubic->setText("バイキュービック");

        QDoubleSpinBox *vertical = new QDoubleSpinBox;
        vertical->setMaximum(100);
        vertical->setValue(1.00);

        QDoubleSpinBox *horizontal = new QDoubleSpinBox;
        horizontal->setMaximum(100);
        horizontal->setValue(1.00);

        QGridLayout *grid = new QGridLayout;
        grid->addWidget(nearest,1,0);
        grid->addWidget(vertLabel,1,1);
        grid->addWidget(vertical,1,2);
        grid->addWidget(label1,1,3);
        grid->addWidget(biliner,2,0);
        grid->addWidget(horiLabel,2,1);
        grid->addWidget(horizontal,2,2);
        grid->addWidget(label2,2,3);
        grid->addWidget(bicubic,3,0);
        grid->addWidget(buttonBox,5,2);


        QDialog *dialog = new QDialog(this);
        dialog->setModal(true);
        dialog->setMinimumSize(150,150);
        dialog->setWindowTitle(tr("拡大縮小"));
        dialog->setLayout(grid);




        connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        int button = dialog->exec();  // 1:Ok(送信), 0:Cancel(閉じる)

        if(!Src.empty()){

            double vert = vertical->value();
            double hori = horizontal->value();
            QString about;
            if(button == 1){
                cv::Mat clear;
                setPixmapImage(opcvToQpixmap(clear));
                if(nearest->isChecked()){
                    cv::resize(Src,Src,cv::Size(),hori,vert,cv::InterpolationFlags::INTER_NEAREST);
                    about = "INTER_NEAREST";
                }else if(biliner->isChecked()){
                    cv::resize(Src,Src,cv::Size(),hori,vert,cv::InterpolationFlags::INTER_LINEAR_EXACT);
                    about = "INTER_LINEAR_EXACT";
                }else if(bicubic->isChecked()){
                    cv::resize(Src,Src,cv::Size(),hori,vert,cv::InterpolationFlags::INTER_CUBIC);
                    about = "INTER_CUBIC";
                }else{
                   unselectMethodError();
                }
                setPixmapImage(opcvToQpixmap(Src));
                uimg = Src.clone();
                ui->doname->setText(ui->doname->text() + ":拡大縮小:" + about+ ":" + QString::number(hori) + "×" + QString::number(vert));
            }
        }else{
            unreadableError();
        }
    }else{
        unreadError();
    }



}

void MainWindow::on_grayscale_released()
{
    if(!uimg.empty()){
        if(uimg.channels() == 1){
            QLabel *message = new QLabel;
            message->setText("すでにグレースケール化されています");

            QPushButton *bt = new QPushButton;
            bt->setText("OK");

            QVBoxLayout *vbox = new QVBoxLayout;
            vbox->addWidget(message);
            vbox->addWidget(bt);

            QDialog *dialog = new QDialog(this);
            dialog->setModal(true);
            dialog->setMinimumSize(150,150);
            dialog->setWindowTitle(tr("グレースケール化"));
            dialog->setLayout(vbox);
            connect(bt, SIGNAL(released()), dialog, SLOT(reject()));
            dialog->exec();
        }else{
            cv::Mat Src = uimg.clone();
            QLabel *message = new QLabel;
            message->setText("グレースケール化を実行しますか?");

            QDialogButtonBox *buttonBox = new QDialogButtonBox(
                QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
            );
            buttonBox->button(QDialogButtonBox::Ok)->setText(tr("実行"));
            buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("キャンセル"));

            QVBoxLayout *vbox = new QVBoxLayout;
            vbox->addWidget(message);
            vbox->addWidget(buttonBox);

            QDialog *dialog = new QDialog(this);
            dialog->setModal(true);
            dialog->setMinimumSize(150,150);
            dialog->setWindowTitle(tr("グレースケール化"));
            dialog->setLayout(vbox);

            connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
            connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

            int button = dialog->exec();  // 1:Ok(送信), 0:Cancel(閉じる)

            if(!Src.empty()){
                if(button == 1){
                    cv::Mat clear;
                    setPixmapImage(opcvToQpixmap(clear));
                    Src.convertTo(Src,CV_32F,1.0/255.0);
                    cv::cvtColor(Src,Src,cv::COLOR_BGR2GRAY);
                    setPixmapImage(opcvToQpixmap(Src));
                    uimg = Src.clone();
                    ui->doname->setText(ui->doname->text() + ":グレースケール化");
                }
            }else{
                unreadableError();
            }
        }


    }else{
        unreadError();
    }

}

void MainWindow::on_edge_released()
{
    if(!uimg.empty()){
        cv::Mat Src = uimg.clone();
        cv::Mat ctsrc,gray,ctdst,dst;
        if(Src.type() != 5){
            Src.convertTo(ctsrc,CV_32F,1.0/255.0);
            cv::cvtColor(ctsrc,gray,cv::COLOR_BGR2GRAY);

        }else{
            gray = Src;
        }

        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
        );
        buttonBox->button(QDialogButtonBox::Ok)->setText(tr("実行"));
        buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("キャンセル"));


        QLabel *laplabel = new QLabel;
        laplabel->setText("ラプラシアンフィルタ");
        QRadioButton *lapkernel1 = new QRadioButton;
        lapkernel1->setText("カーネルサイズ1");
        lapkernel1->setChecked(true);
        QRadioButton *lapkernel2 = new QRadioButton;
        lapkernel2->setText("カーネルサイズ3");
        QRadioButton *lapkernel3 = new QRadioButton;
        lapkernel3->setText("カーネルサイズ5");
        QRadioButton *lapkernel4 = new QRadioButton;
        lapkernel4->setText("カーネルサイズ7");
        QLabel *sobellabel = new QLabel;
        sobellabel->setText("Sobelフィルタ");
        QRadioButton *sobelx = new QRadioButton;
        sobelx->setText("x方向");
        QRadioButton *sobely = new QRadioButton;
        sobely->setText("y方向");
        QRadioButton *sobelxy = new QRadioButton;
        sobelxy->setText("x,y方向");
        QLabel *cannylabel = new QLabel;
        cannylabel->setText("Cannyフィルタ");
        QLabel *cannylabel1 = new QLabel;
        cannylabel1->setText("閾値1");
        QLabel *cannylabel2 = new QLabel;
        cannylabel2->setText("閾値2");
        QRadioButton *canny = new QRadioButton;
        canny->setText("Cannyフィルタ");
        QDoubleSpinBox *siki1 = new QDoubleSpinBox;
        siki1->setMinimum(0);
        siki1->setMaximum(255);

        siki1->setValue(50);
        QDoubleSpinBox *siki2 = new QDoubleSpinBox;
        siki2->setMinimum(siki1->value());
        siki2->setMaximum(255);

        siki2->setValue(100);

        QGridLayout *grid = new QGridLayout;
        grid->addWidget(laplabel,1,0);
        grid->addWidget(lapkernel1,2,0);
        grid->addWidget(lapkernel2,2,1);
        grid->addWidget(lapkernel3,2,2);
        grid->addWidget(lapkernel4,2,3);
        grid->addWidget(sobellabel,3,0);
        grid->addWidget(sobelx,4,0);
        grid->addWidget(sobely,4,1);
        grid->addWidget(sobelxy,4,2);
        grid->addWidget(cannylabel,5,0);
        grid->addWidget(canny,6,0);
        grid->addWidget(cannylabel1,6,1);
        grid->addWidget(siki1,6,2);
        grid->addWidget(cannylabel2,7,1);
        grid->addWidget(siki2,7,2);
        grid->addWidget(buttonBox,8,3);


        QDialog *dialog = new QDialog(this);
        dialog->setModal(true);
        dialog->setMinimumSize(150,150);
        dialog->setWindowTitle(tr("エッジ検出"));
        dialog->setLayout(grid);

        connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        int button = dialog->exec();  // 1:Ok(送信), 0:Cancel(閉じる)

        if(!Src.empty()){

            if(button == 1){
                cv::Mat clear;
                QString about;
                setPixmapImage(opcvToQpixmap(clear));
                if(lapkernel1->isChecked()){
                    cv::Laplacian(gray,Src,CV_32F,1,cv::BORDER_DEFAULT);
                    about = "laplacianサイズ1";
                }else if(lapkernel2->isChecked()){
                    cv::Laplacian(gray,Src,CV_32F,3,cv::BORDER_DEFAULT);
                    about = "laplacianサイズ3";
                }else if(lapkernel3->isChecked()){
                    cv::Laplacian(gray,Src,CV_32F,5,cv::BORDER_DEFAULT);
                    about = "laplacianサイズ5";
                }else if(lapkernel4->isChecked()){
                    cv::Laplacian(gray,Src,CV_32F,7,cv::BORDER_DEFAULT);
                    about = "laplacianサイズ7";
                }else if(sobelx->isChecked()){
                    cv::Sobel(gray, Src, CV_32F, 1, 0, 1);
                    about = "sobel x方向";
                }else if(sobely->isChecked()){
                    cv::Sobel(gray, Src, CV_32F, 0, 1, 1);
                    about = "sobel y方向";
                }else if(sobelxy->isChecked()){
                    cv::Sobel(gray, Src, CV_32F, 1, 1, 1);
                    about = "sobel xy方向";
                }else if(canny->isChecked()){
                    Src.convertTo(Src,CV_8U,1,0);
                    cv::Canny(Src,Src,siki1->value(),siki2->value());
                    about = "canny" + QString::number(siki1->value()) + " "+ QString::number(siki2->value()) ;
                }else{
                  unselectMethodError();
                }

                setPixmapImage(opcvToQpixmap(Src));
                uimg = Src.clone();
                ui->doname->setText(ui->doname->text() + ":エッジ検出:" + about);
            }
        }else{
            unreadableError();
        }
    }else{
        unreadError();
    }
}

void MainWindow::on_filtering_released()
{
    if(!uimg.empty()){
        QString about;
        cv::Mat Src = uimg.clone();
        cv::Mat dst;
        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
        );
        buttonBox->button(QDialogButtonBox::Ok)->setText(tr("実行"));
        buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("キャンセル"));

        QRadioButton *blur = new QRadioButton;
        blur->setText("平均化フィルタ");
        blur->setChecked(true);
        QRadioButton *median = new QRadioButton;
        median->setText("メディアンフィルタ");
        QRadioButton *gaus = new QRadioButton;
        gaus->setText("ガウシアンフィルタ");
        QRadioButton *kern3 = new QRadioButton;
        kern3->setText("カーネルサイズ3");
        kern3->setChecked(true);
        QRadioButton *kern5 = new QRadioButton;
        kern5->setText("カーネルサイズ5");
        QRadioButton *kern7 = new QRadioButton;
        kern7->setText("カーネルサイズ7");

        QButtonGroup *bg = new QButtonGroup;
        bg->addButton(blur);
        bg->addButton(median);
        bg->addButton(gaus);

        QButtonGroup *kg = new QButtonGroup;
        kg->addButton(kern3);
        kg->setId(kern3,3);
        kg->addButton(kern5);
        kg->setId(kern5,5);
        kg->addButton(kern7);
        kg->setId(kern7,7);

        QGridLayout *grid = new QGridLayout;
        grid->addWidget(blur,1,0);
        grid->addWidget(median,2,0);
        grid->addWidget(gaus,3,0);
        grid->addWidget(kern3,1,1);
        grid->addWidget(kern5,2,1);
        grid->addWidget(kern7,3,1);
        grid->addWidget(buttonBox,4,1);


        QDialog *dialog = new QDialog(this);
        dialog->setModal(true);
        dialog->setMinimumSize(150,150);
        dialog->setWindowTitle(tr("平滑化"));
        dialog->setLayout(grid);

        connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        int button = dialog->exec();  // 1:Ok(送信), 0:Cancel(閉じる)

        if(!Src.empty()){

            if(button == 1){
                int size = kg->checkedId();
                cv::Mat clear;
                setPixmapImage(opcvToQpixmap(clear));
                if(blur->isChecked()){
                    cv::blur(Src,Src,cv::Size(size,size),cv::Point(-1,-1),cv::BORDER_DEFAULT);
                    about = "平均化フィルタ:サイズ" + QString::number(size);
                }else if(median->isChecked()){
                    cv::medianBlur(Src,Src,size);
                    about = "メディアンフィルタ:サイズ" + QString::number(size);
                }else if(gaus->isChecked()){
                    cv::GaussianBlur(Src,Src,cv::Size(size,size),cv::BORDER_DEFAULT);
                    about = "ガウシアンフィルタ:サイズ" + QString::number(size);
                }else{
                  unselectMethodError();
                }
                setPixmapImage(opcvToQpixmap(Src));
                uimg = Src.clone();
                ui->doname->setText(ui->doname->text() + ":平滑化:" + about);
            }
        }else{
            unreadableError();
        }
    }else{
        unreadError();
    }
}

void MainWindow::on_nitika_released()
{
    if(!uimg.empty()){
        QString about;
        cv::Mat Src = uimg.clone();
        if(Src.type() == 5){
            Src.convertTo(Src,CV_8U,1,0);
            cv::cvtColor(Src,Src,cv::COLOR_GRAY2BGR);
        }
        cv::Mat dst,gray;
        cv::cvtColor(Src,Src,cv::COLOR_BGR2GRAY);
        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
        );
        buttonBox->button(QDialogButtonBox::Ok)->setText(tr("実行"));
        buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("キャンセル"));

        QLabel *sikii = new QLabel;
        sikii->setText("閾値");

        QRadioButton *bin = new QRadioButton;
        bin->setText("BINARY");
        bin->setChecked(true);
        QRadioButton *bin_inv = new QRadioButton;
        bin_inv->setText("BINARY_INV");
        QRadioButton *tozero = new QRadioButton;
        tozero->setText("TOZERO");
        QRadioButton *tozero_inv = new QRadioButton;
        tozero_inv->setText("TOZERO_INV");
        QCheckBox *autosikii = new QCheckBox;
        autosikii->setText("閾値自動");


        QDoubleSpinBox *siki1 = new QDoubleSpinBox;
        siki1->setMaximum(255);
        siki1->setValue(50);
        siki1->setSingleStep(10);




        QGridLayout *grid = new QGridLayout;
        grid->addWidget(bin,1,0);
        grid->addWidget(bin_inv,2,0);
        grid->addWidget(tozero,3,0);
        grid->addWidget(tozero_inv,4,0);
        grid->addWidget(siki1,1,2);
        grid->addWidget(autosikii,2,1);
        grid->addWidget(sikii,1,1);
        grid->addWidget(buttonBox,5,2);


        QDialog *dialog = new QDialog(this);
        dialog->setModal(true);
        dialog->setMinimumSize(150,150);
        dialog->setWindowTitle(tr("二値化"));
        dialog->setLayout(grid);


        connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));


        int button = dialog->exec();  // 1:Ok(送信), 0:Cancel(閉じる)

        if(!Src.empty()){

            double sikiichi = siki1->value();
            if(button == 1){
                cv::Mat clear;
                setPixmapImage(opcvToQpixmap(clear));
                if(autosikii->isChecked()){
                    if(bin->isChecked()){
                        cv::threshold(Src,Src,0,255,CV_THRESH_BINARY|cv::THRESH_OTSU);
                        about = "CV_THRESH_BINARY:閾値自動";
                    }else if(bin_inv->isChecked()){
                        cv::threshold(Src,Src,0,255,CV_THRESH_BINARY_INV|cv::THRESH_OTSU);
                        about = "CV_THRESH_BINARY_INV:閾値自動";
                    }else if(tozero->isChecked()){
                        cv::threshold(Src,Src,0,255,CV_THRESH_TOZERO|cv::THRESH_OTSU);
                        about = "CV_THRESH_TOZERO:閾値自動";
                    }else if(tozero_inv->isChecked()){
                        cv::threshold(Src,Src,0,255,CV_THRESH_TOZERO_INV|cv::THRESH_OTSU);
                        about = "CV_THRESH_TOZERO_INV:閾値自動";
                    }else{
                       unselectMethodError();
                    }
                }else{
                    if(bin->isChecked()){
                        cv::threshold(Src,Src,sikiichi,255,CV_THRESH_BINARY);
                        about = "CV_THRESH_BINARY:閾値" + QString::number(sikiichi);
                    }else if(bin_inv->isChecked()){
                        cv::threshold(Src,Src,sikiichi,255,CV_THRESH_BINARY_INV);
                        about = "CV_THRESH_BINARY_INV:閾値"+ QString::number(sikiichi);
                    }else if(tozero->isChecked()){
                        cv::threshold(Src,Src,sikiichi,255,CV_THRESH_TOZERO);
                        about = "CV_THRESH_TOZERO:閾値"+ QString::number(sikiichi);
                    }else if(tozero_inv->isChecked()){
                        cv::threshold(Src,Src,sikiichi,255,CV_THRESH_TOZERO_INV);
                        about = "CV_THRESH_TOZERO_INV:閾値"+ QString::number(sikiichi);
                    }else{
                       unselectMethodError();
                    }
                }
                setPixmapImage(opcvToQpixmap(Src));
                uimg = Src.clone();
                ui->doname->setText(ui->doname->text() + ":二値化:" + about);
            }
        }else{
            unreadableError();
        }
    }else{
        unreadError();
    }

}

void MainWindow::on_rotate_released()
{
    if(!uimg.empty()){
        cv::Mat Src = uimg.clone();
        cv::Mat dst;

        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
        );
        buttonBox->button(QDialogButtonBox::Ok)->setText(tr("実行"));
        buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("キャンセル"));

        QLabel *rote = new QLabel;
        rote->setText("回転角度");
        QLabel *Label = new QLabel;
        Label->setText("度");

        QSpinBox *kakudo = new QSpinBox;
        kakudo->setMinimum(-360);
        kakudo->setMaximum(360);
        kakudo->setValue(0);
        kakudo->setSingleStep(10);

        QGridLayout *grid = new QGridLayout;
        grid->addWidget(rote,1,0);
        grid->addWidget(kakudo,1,1);
        grid->addWidget(Label,1,2);
        grid->addWidget(buttonBox,2,1);


        QDialog *dialog = new QDialog(this);
        dialog->setModal(true);
        dialog->setMinimumSize(150,150);
        dialog->setWindowTitle(tr("回転"));
        dialog->setLayout(grid);


        connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        int button = dialog->exec();  // 1:Ok(送信), 0:Cancel(閉じる)

        if(!Src.empty()){

            int angle = kakudo->value();

            if(button == 1){
                cv::Mat clear;
                setPixmapImage(opcvToQpixmap(clear));
                int x = Src.cols;
                int y = Src.rows;
                double rad = (angle * M_PI)/180.0;
                int ox = abs(cos(rad)) * x + abs(sin(rad)) * y+0.5;//回転後画像の幅
                int oy = abs(sin(rad)) * x + abs(cos(rad)) * y+0.5;//回転後画像の高さ
                cv::Point2f center = cv::Point2f(x/2,y/2);//画像の中心を軸に回転させる
                double scale = 1;

                cv::Mat change= cv::getRotationMatrix2D(center,angle,scale);

                //平行移動
                change.at<double>(0, 2) += -x/2  + ox/2;
                change.at<double>(1, 2) += -y/2  + oy/2;
                cv::warpAffine(Src,Src , change, cv::Size(ox,oy), cv::INTER_CUBIC, cv::BORDER_CONSTANT, cv::Scalar(255, 255, 255)); //アフィン変換

                setPixmapImage(opcvToQpixmap(Src));
                uimg = Src.clone();
                ui->doname->setText(ui->doname->text() + ":回転:角度" + QString::number(angle));
            }
        }else{
            unreadableError();
        }
    }else{
        unreadError();
    }
}

void MainWindow::on_srcshow_released()
{
    if(!img.empty()){
        int check = mapclearmessage();
        if( check == 1){
            cv::Mat src = img.clone();
            cv::Mat clear;
            setPixmapImage(opcvToQpixmap(clear));

            setPixmapImage(opcvToQpixmap(src));
            uimg = src.clone();
            ui->doname->setText("");
            ui->file->setText(fname);
        }

    }else{
        unreadError();
    }

}

void MainWindow::on_clearButton_released()
{
    if(!img.empty()){
        int check = mapclearmessage();
        if(check == 1){
            img.release();
            uimg.release();
            cv::Mat clear;
            setPixmapImage(opcvToQpixmap(clear));
            ui->file->setText("保存場所 ");
            ui->sizeLabel->setText("幅×高さ ");
            ui->Image->resize(600,510);
            ui->scrollArea->widget()->resize(600,510);
            ui->doname->setText("");
        }
    }
}

void MainWindow::on_toukeiButton_released()
{
    if(!uimg.empty()){
        cv::Mat Src = uimg.clone();
        if(Src.channels() == 1){
            int suma=0;
            double avga=0;
            double stva=0;
            double deca=0;

            for(int i=0;i<Src.cols;i++){
                for(int j=0;j<Src.rows;j++){
                    suma += Src.at<uchar>(j,i);
                }
            }
            avga = (double)(suma / (Src.cols*Src.rows));

            for(int i=0;i<Src.cols;i++){
                for(int j=0;j<Src.rows;j++){
                    stva += (Src.at<uchar>(j,i)-avga);
                }
            }
            stva = stva/(Src.cols*Src.rows);
            stva = sqrt(stva);
            deca = stva * stva;

            QPushButton * cls = new QPushButton;
            cls->setText("閉じる");
            QDialog *dialog = new QDialog(this);

            QLabel *avgl = new QLabel;
            avgl->setText("平均:" + QString::number(avga,'f',2));
            QLabel *stvl = new QLabel;
            stvl->setText("標準偏差:" + QString::number(stva,'f',2));
            QLabel *decl = new QLabel;
            decl->setText("分散:" + QString::number(deca,'f',2));

            QGridLayout *grid = new QGridLayout;
            grid->addWidget(avgl,1,0);
            grid->addWidget(stvl,2,0);
            grid->addWidget(decl,3,0);
            grid->addWidget(cls,4,1);


            dialog->setModal(true);
            dialog->setMinimumSize(150,150);
            dialog->setWindowTitle(tr("統計量表示"));
            dialog->setLayout(grid);
            connect(cls, SIGNAL(released()), dialog, SLOT(close()));
            dialog->exec();
        }else{
            QPushButton * cls = new QPushButton;
            cls->setText("閉じる");
            QDialog *dialog = new QDialog(this);

            int sumr=0;
            int sumg=0;
            int sumb=0;
            int maxr=0;
            int maxg=0;
            int maxb=0;
            int minr=0;
            int ming=0;
            int minb=0;
            double avgr=0;
            double avgg=0;
            double avgb=0;
            double stvr=0;
            double stvg=0;
            double stvb=0;
            double decr=0;
            double decg=0;
            double decb=0;

            for(int i=0;i < Src.cols;i++){
                for(int j=0;j < Src.rows;j++){
                    sumb += Src.at<cv::Vec3b>(j,i)[0];
                    sumg += Src.at<cv::Vec3b>(j,i)[1];
                    sumr += Src.at<cv::Vec3b>(j,i)[2];
                    if(maxb <Src.at<cv::Vec3b>(j,i)[0]){

                        maxb = Src.at<cv::Vec3b>(j,i)[0];
                    }
                    if(maxg < Src.at<cv::Vec3b>(j,i)[1]){

                        maxg = Src.at<cv::Vec3b>(j,i)[1];
                    }
                    if(maxr < Src.at<cv::Vec3b>(j,i)[2]){
                        maxr = Src.at<cv::Vec3b>(j,i)[2];
                    }
                    if(minb > Src.at<cv::Vec3b>(j,i)[0]){

                        minb = Src.at<cv::Vec3b>(j,i)[0];
                    }
                    if(ming > Src.at<cv::Vec3b>(j,i)[1]){
                        ming = Src.at<cv::Vec3b>(j,i)[1];
                    }
                    if(minr > Src.at<cv::Vec3b>(j,i)[2]){

                        minr = Src.at<cv::Vec3b>(j,i)[2];
                    }
                }
            }

            avgb = sumb / (Src.cols * Src.rows);
            avgg = sumg / (Src.cols * Src.rows);
            avgr = sumr / (Src.cols * Src.rows);

            for(int i=0;i < Src.cols;i++){
                for(int j=0;j < Src.rows;j++){

                    stvb += (Src.at<cv::Vec3b>(j,i)[0] - avgb);
                    stvg += (Src.at<cv::Vec3b>(j,i)[1] - avgg);
                    stvr += (Src.at<cv::Vec3b>(j,i)[2] - avgr);
                }
            }


            stvb = stvb / (Src.cols * Src.rows);
            stvg = stvg / (Src.cols * Src.rows);
            stvr = stvr / (Src.cols * Src.rows);


            stvb = sqrt(stvb);
            stvg = sqrt(stvg);
            stvr = sqrt(stvr);

            decb = stvb * stvb;
            decg = stvg * stvg;
            decr = stvr * stvr;




            QLabel *red = new QLabel;
            red->setText("赤");
            QLabel *avglr = new QLabel;
            avglr->setText("平均:" + QString::number(avgr,'f',2));
            QLabel *stvlr = new QLabel;
            stvlr->setText("標準偏差:" + QString::number(stvr,'f',2));
            QLabel *declr = new QLabel;
            declr->setText("分散:" + QString::number(decr,'f',2));
            QLabel *maxlr = new QLabel;
            maxlr->setText("最大輝度:" + QString::number(maxr));
            QLabel *minlr = new QLabel;
            minlr->setText("最低輝度:" + QString::number(minr));

            QLabel *green = new QLabel;
            green->setText("緑");
            QLabel *avglg = new QLabel;
            avglg->setText("平均:" + QString::number(avgg,'f',2));
            QLabel *stvlg = new QLabel;
            stvlg->setText("標準偏差:" + QString::number(stvg,'f',2));
            QLabel *declg = new QLabel;
            declg->setText("分散:" + QString::number(decg,'f',2));
            QLabel *maxlg = new QLabel;
            maxlg->setText("最大輝度:" + QString::number(maxg));
            QLabel *minlg = new QLabel;
            minlg->setText("最低輝度:" + QString::number(ming));

            QLabel *blue = new QLabel;
            blue->setText("青");
            QLabel *avglb = new QLabel;
            avglb->setText("平均:" + QString::number(avgb,'f',2));
            QLabel *stvlb = new QLabel;
            stvlb->setText("標準偏差:" + QString::number(stvb,'f',2));
            QLabel *declb = new QLabel;
            declb->setText("分散:" + QString::number(decb,'f',2));
            QLabel *maxlb = new QLabel;
            maxlb->setText("最大輝度:" + QString::number(maxb));
            QLabel *minlb = new QLabel;
            minlb->setText("最低輝度:" + QString::number(minb));



            QGridLayout *grid = new QGridLayout;
            grid->addWidget(red,2,0);
            grid->addWidget(avglr,3,1);
            grid->addWidget(stvlr,3,2);
            grid->addWidget(declr,3,3);
            grid->addWidget(maxlr,3,4);
            grid->addWidget(minlr,3,5);
            grid->addWidget(green,4,0);
            grid->addWidget(avglg,5,1);
            grid->addWidget(stvlg,5,2);
            grid->addWidget(declg,5,3);
            grid->addWidget(maxlg,5,4);
            grid->addWidget(minlg,5,5);
            grid->addWidget(blue,6,0);
            grid->addWidget(avglb,7,1);
            grid->addWidget(stvlb,7,2);
            grid->addWidget(declb,7,3);
            grid->addWidget(maxlb,7,4);
            grid->addWidget(minlb,7,5);
            grid->addWidget(cls,8,5);


            dialog->setModal(true);
            dialog->setMinimumSize(150,150);
            dialog->setWindowTitle(tr("統計量表示"));
            dialog->setLayout(grid);


            connect(cls, SIGNAL(released()), dialog, SLOT(close()));


            dialog->exec();
        }

    }else{
        unreadError();
    }
}

void MainWindow::on_changeSrcButton_released()
{
    if(!uimg.empty()){
        cv::Mat Src = uimg.clone();
        cv::Mat dst;
        QLabel *message = new QLabel;
        message->setText("現在の画像を原画像に上書きします。よろしいですか?");

        QDialogButtonBox *buttonBox = new QDialogButtonBox(
            QDialogButtonBox::Ok | QDialogButtonBox::Cancel, Qt::Horizontal
        );
        buttonBox->button(QDialogButtonBox::Ok)->setText(tr("はい"));
        buttonBox->button(QDialogButtonBox::Cancel)->setText(tr("いいえ"));

        QVBoxLayout *vbox = new QVBoxLayout;
        vbox->addWidget(message);
        vbox->addWidget(buttonBox);

        QDialog *dialog = new QDialog(this);
        dialog->setModal(true);
        dialog->setMinimumSize(150,150);
        dialog->setWindowTitle(tr("原画像の上書き"));
        dialog->setLayout(vbox);

        connect(buttonBox, SIGNAL(accepted()), dialog, SLOT(accept()));
        connect(buttonBox, SIGNAL(rejected()), dialog, SLOT(reject()));

        int button = dialog->exec();  // 1:Ok(送信), 0:Cancel(閉じる)

        if(!Src.empty()){
            if(button == 1){
                cv::Mat clear;
                setPixmapImage(opcvToQpixmap(clear));
                img = uimg.clone();
                setPixmapImage(opcvToQpixmap(img));
                ui->doname->setText(ui->doname->text() + ":原画像上書き:");
            }
        }else{
            unreadableError();
        }

    }else{
        unreadError();
    }
}

void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    if(!uimg.empty()){
        cv::Mat Src = uimg.clone();
        cv::Mat dst;
        if(!Src.empty()){
           double p = (double)(arg1 * 0.01);
           cv::resize(Src,dst,cv::Size(),p,p,cv::InterpolationFlags::INTER_CUBIC);
           int w = dst.cols;
           int h = dst.rows;
           ui->Image->setMinimumSize(w,h);
           ui->scrollArea->widget()->resize(w,h);
           ui->Image->resize(ui->scrollArea->widget()->width(),ui->scrollArea->widget()->height());
           ui->Image->setPixmap(opcvToQpixmap(dst));

        }else{
            unreadableError();
        }
    }

}



