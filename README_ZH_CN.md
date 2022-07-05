# bfc

[![Bless](https://img.shields.io/badge/bless-Alpaca-brightgreen?style=flat-square)](http://lunagao.github.io/BlessYourCodeTag/)

**bfc** 是 BrainFuck Compiler 的缩写形式。
它能将 Brainfxxk 源代码转化为 AT&T 风格的 x86_64 汇编。

## 构建

``` bash
git clone https://github.com/AtomAlpaca/bfc.git
cd ./bfc/src
make
```

## 使用

``` bash
bfc <source_file> <output_file>
```

不提供输出文件名称是可行的。

## 开源协议

bfc 遵循[GNU通用公共许可证第二版](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html)进行开源
