cmake_minimum_required(VERSION 3.14)

project(ToDoApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qtパッケージの検索(widgetsとCore)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# 自動MOC/UIC/RCCの有効化
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# 実行ファイルの追加
add_executable(ToDoApp
  main.cpp
)

# Qtライブラリのリンク
target_link_libraries(ToDoApp
  Qt6::Widgets
)