数据结构与算法
=============

数据结构与算法中提到的一些概念以及算法的实现。

# 调试/运行

项目使用VSCode编写，已经配置好，若需要在本地运行你需要修改你成你自己的本地环境。配置在 ```.vscode``` 目录下：

```launch.json``` 这个文件是运行调试配置文件。

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "preLaunchTask":"build",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": true,
            "MIMode": "gdb",
            // 不使用VS或者VC++ IDE的情况下我们使用 MinGW 环境编译C语言代码
            "miDebuggerPath": "D:/DevTools/MinGW/bin/gdb.exe", // 这里需要替换成你自己的gdb路径
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ]
        }
    ],
    
}
```

```tasks.json``` 配置了调试之前的编译任务。

```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "label": "build",
            "type": "shell",
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "presentation": {
                "echo": true,
                "reveal": "always",
                "focus": false,
                "panel": "shared"
            },
            "windows": {
                "command": "g++", // 这里直接使用了 MinGW 中的 g++ 命令，你需要配置一下你的环境变量
                "args": [
                    "-ggdb",
                    "\"${file}\"",
                    "--std=c++11",
                    "-o",
                    "\"${fileDirname}\\${fileBasenameNoExtension}.exe\""
                ]
            }
        }
    ]
}
```

*配置完成后打开你想要运行的c文件，然后按下 ```F5``` 或者菜单栏中找到调试选择 “启动调试”；
这里是启动调试，控制台应用程序运行结束后控制台会马上消失不能看到控制中输出的内容，你可以使用终端直接运行 *.exe 即可查看运行结果。*
