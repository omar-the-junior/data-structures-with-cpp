

# Code implementation for Data Structures using C++
The repository contains code implementation of concepts explained in the book  [Data structures using C++
by Malik, D. S 2nd Edition](https://archive.org/details/datastructuresus0000mali).

> [!NOTE]
> The goal of this repository is to help students start exploring the code right away and get their hands dirty as soon as possible. This would be helpful especially if a student faced lots of bugs while trying to implement the code for the first time.


## Table of Contents
- [Code implementation for Data Structures using C++](#code-implementation-for-data-structures-using-c)
  - [Table of Contents](#table-of-contents)
  - [How to get started?](#how-to-get-started)
    - [Using codespaces](#using-codespaces)
      - [Run the code on codespaces](#run-the-code-on-codespaces)
    - [Work locally](#work-locally)
      - [Code Runner Configuration](#code-runner-configuration)
        - [Windows Users](#windows-users)
        - [Linux Users](#linux-users)
  - [Get familiar with the repository](#get-familiar-with-the-repository)
    - [File structure](#file-structure)
      - [Root Directories](#root-directories)
      - [Chapters](#chapters)
      - [Concepts](#concepts)
    - [Code declaration VS definition](#code-declaration-vs-definition)
      - [Code declaration (Header files)](#code-declaration-header-files)
        - [Header Guards](#header-guards)
      - [Code definition](#code-definition)

## How to get started?

### Using codespaces
[![Open in GitHub Codespaces](https://img.shields.io/static/v1?style=for-the-badge&label=GitHub+Codespaces&message=Open&color=lightgrey&logo=github)](https://codespaces.new/omar-the-junior/data-structures-with-cpp)
#### Run the code on codespaces
> [!TIP]
> You can either run the code by clicking the ▶️ run button on the top right corner or use the <kbd>Ctrl</kbd> + <kbd>Alt</kbd> + <kbd>N</kbd> shortcut 
> <video controls src="https://github.com/omar-the-junior/data-structures-with-cpp/assets/44696488/75cef5fb-857e-4e4d-a27c-4f644977aa0c" title="Title"></video>
### Work locally
1. Clone the repo `git clone https://github.com/omar-the-junior/data-structures-with-cpp`
2. Open the repo using your favorite editor (VS Code is recommended)

#### Code Runner Configuration

To avoid linker errors by compiling all `.cpp` files in the `src` folder, it's crucial to set up the `executorMap` in the Code Runner extension settings. This can be done in the `.vscode/settings.json` file in your workspace.

##### Windows Users

If you're using Windows, use the following `executorMap` in [the workspace settings](./.vscode/settings.json):

```json
"code-runner.executorMap": {
  "cpp": "cd $dir && g++ *.cpp -o $fileNameWithoutExt && $dir$fileNameWithoutExt"
}
```
##### Linux Users

If you're using Linux, use the following executorMap in [the workspace settings](./.vscode/settings.json):

```json
"code-runner.executorMap": {
  "cpp": "cd $dir && mkdir -p bin && g++ *.cpp -o bin/$fileNameWithoutExt && $dirbin/$fileNameWithoutExt",
}
```

## Get familiar with the repository

### File structure
File structure would look as follows:

> [!NOTE]
> The following file tree is just a demonstration of how the file structure should look.
```
├── 1-chapter-name
│   ├── concept-name
│   │   ├── include
│   │   │   └── fileName.h
│   │   └── src
│   │       ├── main.cpp
│   │       └── fileName.cpp
│   ├── another-concept-name
│   │   ├── include
│   │   │   └── fileName.h
│   │   └── src
│   │       ├── main.cpp
│   │       └── fileName.cpp
├── 2-chapter-name
│   ├── concept-name
│   │   ├── include
│   │   │   └── fileName.h
│   │   └── src
│   │       ├── main.cpp
│   │       └── fileName.cpp
```
#### Root Directories
At the root directory lies a folder for each chapter
```
├── 1-chapter-name
├── 2-chapter-name
├── 3-chapter-name
```
Each folder is named with the **chapter number** first, followed by the **chapter name**.

#### Chapters
Inside Each chapter folders lies a folder for each concept
```
├── 1-chapter-name
│   ├── concept-name
```

#### Concepts
Each concept contains mainly two folders `include` for header files `src` for `.cpp` files
```
├── 1-chapter-name
│   ├── concept-name
│   │   ├── include
│   │   │   └── fileName.h
│   │   └── src
│   │       ├── main.cpp
│   │       └── fileName.cpp   
```

> [!NOTE]
The `include` folder contains the code **declaration** of a specific `class` or `function`. While all the **definitions** lie in the `src` folder.

### Code declaration VS definition

#### Code declaration (Header files)
```
├── friend-functions-of-classes
│   ├── include
│   │   └── classIllusFriend.h
│   └── src
│       ├── bin
│       │   └── main
│       ├── classIllusFriend.cpp
│       ├── main.cpp
│       └── main.exe
```

The following is the code declaration inside the header file `include/classIllusFriend.h`
```cpp
#ifndef H_classIllusFriend
#define H_classIllusFriend

class classIllusFriend
{
    friend void friendFunc(classIllusFriend cIFObject);

private:
    int x;

public:
    void print();
    void setX(int a);
};

#endif
```

##### Header Guards 

> [!IMPORTANT]
> Make sure to use [Header Guards](https://www.learncpp.com/cpp-tutorial/header-guards/) in header files to prevent multiple inclusions.
> ```cpp
> #ifndef FILE_H
> #define FILE_H
> 
> /* ... Declarations etc here ... */
> 
> #endif
> ```

#### Code definition 
```cpp
#include <iostream>
#include <string>
#include "../include/classIllusFriend.h"

using namespace std;

void classIllusFriend::print()
{
    cout << "In class ClassIllusFriend: x = " << x << endl;
}

void classIllusFriend::setX(int a)
{
    x = a;
}

void friendFunc(classIllusFriend cIFObject)
{
    classIllusFriend localTwoObject;

    localTwoObject.x = 45;

    localTwoObject.print();

    cout << "Line 25: in friendFunc accesing "
         << "private member variable "
         << "x = "
         << localTwoObject.x << endl;

    cIFObject.x = 88;
    cIFObject.print();

    cout << "Line 32: in friendFunc accesing "
         << "private member variable "
         << "x = "
         << cIFObject.x << endl;
}
```

> [!WARNING]
> When writing template classes or functions, the declaration and definition should be in the same file. This is because the compiler needs to see the entire template definition at the point of instantiation.

