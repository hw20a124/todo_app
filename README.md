# Qt製ToDoアプリ

このアプリは、C++とQtを使用して作成したシンプルなToDo管理アプリです。タスクの追加、編集、削除、期限設定、ファイル保存、読み込みといった基本的な機能を備えています。

## 使用技術

- C++
- Qt 6
- CMake

## 主な機能

- タスクの追加・編集・削除
- 各タスクに期限(締切日)を設定可能
- アプリ終了時にタスク一覧をファイルに自動保存
- 起動時に前回保存したタスクを読み込み
- 過去の日付を期限に設定しようとすると警告表示

## ビルド方法

このアプリはCMakeを使ってビルドできます。

```bash
git clone https://github.com/hw20a124/todo_app.git
cd ToDoApp/build
cmake ..
cmake --build .

./ToDoApp
```

## フォルダ構成
```
todo_app/
├── CMakeLists.txt
├── main.cpp
├── build/tasks.txt     # 保存されたタスク情報
└── README.md
```
## 作者情報

- 制作者:溝内 航


