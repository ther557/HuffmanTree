# HuffmanTree
compress_file_by_using_HuffmanTree
【2020/11/22更新网页版查看docx等文件方法】

后缀为.docx的项目分工文件需要下载或者ViewRaw查看

【2020/11/16添加了本仓库基本介绍】

本仓库用为中国石油大学（北京）本科20级电子信息专业四位新生小组合作项目。项目完成目标为压缩、解压缩文件并输出存储结构。其中会涉及到HuffmanTree、数据结构堆等知识点的运用。

项目周期为四周。第五周进行展示。

【2020/11/13仓库建立】

# Notice
项目最终输出结果为bin/Myzip和bin/Myunzip。

分别完成对于文件的压缩和解压缩。

用法为
```shell script
Myzip.exe file_before file.ezip
Myunzip.exe file.ezip file_after
```
file为任意可读文件

ezip后缀为自己定义的文件格式，需要有一定的文件结构。

比如：
```c
code_title/// a signal to confirm 'ezip'
BeginHuffmanTree
/// structure of HuffmanTree
EndHuffmanTree
00110100
//data of compressed file......
00010100
EOF
```
开始保存一个title来确认是否为ezip格式，否则需要做错误处理。

接着存储HuffmanTree方便对于后面的二进制数据进行读取。


# Build
使用Makefile对项目进行编译，建议先将部分源文件编译为静态库/动态库，然后再编译为可执行文件。