#include <QApplication>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QListWidgetItem>
#include <QFile>
#include <QTextStream>
#include <QDateEdit>
#include <QLabel>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

void loadTasks(QListWidget *list)
{
  QFile file("tasks.txt");
  if(file.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QTextStream in(&file);
    while(!in.atEnd())
    {
      QString line = in.readLine();
      QStringList parts = line.split(":");
      if(parts.size() >= 2)
      {
        QString checkState = parts[0];
        QString titleWithDate = parts[1];

        //正規表現でタイトルと期限を分離
        QRegularExpression rx("^(.*) (期限: (\\d{4}-\\d{2}-\\d{2})) $");
        QRegularExpressionMatch match = rx.match(titleWithDate);

        QString title = titleWithDate;
        QString dateStr = "";

        if(match.hasMatch())
        {
          title = match.captured(1);
          dateStr = match.captured(2);
        }

        QListWidgetItem *item = new QListWidgetItem(title + (dateStr.isEmpty() ? "" : "(期限: " + dateStr + ") "));
        item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        item->setCheckState(checkState == "1" ? Qt::Checked : Qt::Unchecked);
        if(item->checkState() == Qt::Checked)
        {
          item->setForeground(Qt::gray);
        }
        list->addItem(item);
      }
    }
    file.close();
  }
}

void saveTasks(QListWidget *list)
{
  QFile file("tasks.txt");
  if(file.open(QIODevice::WriteOnly | QIODevice::Text))
  {
    QTextStream out(&file);
    for (int i = 0; i < list->count(); ++i)
    {
      QListWidgetItem *item = list->item(i);
      QString text = item->text();
      out << (item->checkState() == Qt::Checked ? "1" : "0") << ":" << text << "\n";
    }
    file.close();
  }
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  QWidget window;
  window.setWindowTitle("期限付きToDoリスト");

  //ウィジェットの作成
  QLineEdit *input = new QLineEdit;
  QDateEdit *dateEdit = new QDateEdit(QDate::currentDate());
  dateEdit->setCalendarPopup(true);

  QPushButton *addButton = new QPushButton("追加");
  QPushButton *removeButton = new QPushButton("削除");
  QPushButton *clearCompleteButton = new QPushButton("完了済みを削除");
  QListWidget *list = new QListWidget;

  //入力部分のレイアウト
  QHBoxLayout *inputLayout = new QHBoxLayout;
  inputLayout->addWidget(input);
  inputLayout->addWidget(dateEdit);
  inputLayout->addWidget(addButton);

  //全体レイアウト
  QVBoxLayout *mainLayout = new QVBoxLayout;
  mainLayout->addLayout(inputLayout);
  mainLayout->addWidget(list);
  mainLayout->addWidget(removeButton);
  mainLayout->addWidget(clearCompleteButton);

  window.setLayout(mainLayout);

  //タスクの読み込み
  loadTasks(list);

  //タスク追加処理
  QObject::connect(addButton, &QPushButton::clicked, [input, list, dateEdit]()
                   { QString text = input->text(); 
      if(text.isEmpty())
      {
        QMessageBox::warning(nullptr, "警告", "入力が空です");
        return;
      }

      if(dateEdit->date() < QDate::currentDate())
      {
        QMessageBox::warning(nullptr, "警告", "過去の日付は指定できません");
        return;
      }

      QString deadline = dateEdit->date().toString("yyyy-MM-dd");
      QString itemText = text + "(期限: " + deadline + ")";
      
      QListWidgetItem *item = new QListWidgetItem(itemText);
      item->setFlags(item->flags() | Qt::ItemIsEditable | Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
      item->setCheckState(Qt::Unchecked);
      list->addItem(item);
      input->clear(); });
  
  //削除ボタン処理
  QObject::connect(removeButton, &QPushButton::clicked, [list]()
  { QListWidgetItem *item = list->currentItem();
    if(item)
    {
      delete list->takeItem(list->row(item));
    }
  });

  //完了済みタスク削除
  QObject::connect(clearCompleteButton, &QPushButton::clicked, [list]()
    { for (int i = list->count() - 1; i >= 0; --i) 
        {
          QListWidgetItem *item = list->item(i);
          if(item->checkState() == Qt::Checked)
          {
            delete list->takeItem(i);
          }
        } });

  //チェック状態変更時の色変更
  QObject::connect(list, &QListWidget::itemChanged, [list](QListWidgetItem *item)
    {
      if(item->checkState() == Qt::Checked)
      {
        item->setForeground(Qt::gray);
      }
      else
      {
        item->setForeground(Qt::black);
      }
    });

  //アプリ終了時に保存
  QObject::connect(&app, &QApplication::aboutToQuit, [&]()
    { saveTasks(list); });

  window.show();
  return app.exec();
}