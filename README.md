# C Final Project 2017

In this project, we are going to develop a system to help teacher grade assignments.

See the project guideline for details.

## Building

On Linux or Windows with Cygwin / MSYS / WSL:

```bash
make clean     # Clean the repository
make           # Do a release build with optimizations
# make DEBUG=1 # Do a debug build with debugging symbols and no optimizations
```

On Windows with Visual Studio, see [Setup project in Visual Studio](#setup-project-in-visual-studio) below.

## Naming <!-- Disclaimer -->

Per requirement, suffixes for all C source code files are `.cpp`, and all C header files are `.hpp`.

## Commit Messages

Write commit messages in the form of:

```
<part>: <description>
```

In which:

- `<part>` should be file name(s), folder name(s), etc.
- `<description>` should be a brief description on what you do in the commit, (generally) no more than 60 characters.
  - Starting with a verb (add, change, edit, remove, etc) is preferred.

## Setup project in Visual Studio

1. Create an **empty** **Command Line Program** project in Visual Studio
2. Right click your solution in Solution Explorer and choose **"Open Folder in File Explorer"**
3. Right click your mouse in File Explorer and choose **"Git Bash"**, then type in

```shell
$ git init
$ git remote add origin https://github.com/lmy441900/COMP1013-Final-Project
$ git pull origin master
```

4. Then go back to Visual Studio and right click **Head Files** in Solution Explorer and then **Add -> Existing Items** and add all the **.hpp** files in **src** folder. Then right click Source Files in Solution Explorer and then  **Add -> Existing Items** and add all the **.cpp** files in **src** folder.
5. You can start to code and run the program, and every time you want to push to GitHub or pull from GitHub, follow step 2 and 3.
