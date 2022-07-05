# bfc

**bfc** 意味着 **BrainFuck Compiler**。
bfc 能將 Brainfxxk 源代碼轉化爲 AT&T 風格的 x86_64 匯編源碼。

## 構建

``` bash
git clone https://github.com/AtomAlpaca/bfc.git
cd ./bfc/src
make
```
## 使用

``` bash
bfc <source_file> <output_file>
```

不提供輸出文件名稱是可行的。

## license

bfc 遵循[GNU通用公共許可証第二版進行開源](https://www.gnu.org/licenses/old-licenses/gpl-2.0.html)
