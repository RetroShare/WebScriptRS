#include "webtabcontents.h"
#include "ui_webtabcontents.h"

//#incude "QTextBrowser"

WebTabContents::WebTabContents(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WebTabContents)
{
    ui->setupUi(this);
    webview = new WebViewRS();
    //QTextBrowser
    this->ui->verticalLayout->addWidget(webview,1);
    webview->show();
    QString loadfirst = "";//QDir::homePath();

    loadfirst.append("html/index.html");
    webview->setUrl(QUrl(loadfirst));


    //jslog = new QTextBrowser();
    //this->ui->verticalLayout->addWidget(jslog,1);
    //jslog->show();
    QWebSettings::globalSettings()->setAttribute(QWebSettings::DeveloperExtrasEnabled, true);

    //connect(ui->testButton, SIGNAL(clicked()), this->webview, SLOT(reload()));
    connect(ui->testButton, SIGNAL(clicked()), this, SLOT(changeLocation()));


    connect(ui->lineEdit, SIGNAL(returnPressed()), SLOT(changeLocation()));
    connect(webview, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
}

WebTabContents::~WebTabContents()
{
    delete ui;
}

void WebTabContents::changeLocation()
{
    QUrl url = QUrl(ui->lineEdit->text());
    webview->load(url);
    webview->setFocus();
}
void WebTabContents::adjustLocation()
{
    ui->lineEdit->setText(webview->url().toString());
}

void WebTabContents::setP3service(p3JsonRS *p3servicein)
{
    webview->setP3service(p3servicein);
    //p3service = p3servicein;
}
