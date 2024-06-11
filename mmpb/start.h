#ifndef START_H
#define START_H

#include <QWidget>
#include<QPushButton>
#include <QProcess>
#include<QPainter>

//开始界面
class Start : public QWidget
{
    Q_OBJECT
public:
    explicit Start(QWidget *parent = nullptr);

    void run();

    QPushButton *btn_begin = new QPushButton("Start Game",this);
    QPushButton *btn_Ins = new QPushButton("Instruction",this);

protected:
    virtual void paintEvent(QPaintEvent* ev)override;

public slots:
    void openDocxFile() {
        QString filePath = "Instruction.docx"; // 替换为你的文件路径
        QStringList arguments;
        arguments << "winword.exe" << filePath;
        QProcess::startDetached("cmd.exe", QStringList() << "/C" << "start" << arguments);
    }
signals:

};

static int begin_flag = 0;
#endif // START_H

