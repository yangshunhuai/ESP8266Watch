# ESP8266Watch
ESP8266 WiFi模组自制可穿戴智能手表

## 功能
1. 使用内置DS1302时钟芯片提供RTC时钟。
2. 鉴于DS1302芯片准确性不高，也可连接WiFi后通过NTP时钟服务器同步时间。
3. 可以使用计时器、定时器等功能。
4. 访问本地文件系统文件或者连接服务器，阅读文本内容。
5. 具有可拓展性（往上面加点简单游戏什么的完全可以）。

## 版本

这个手表有两个版本：

1. dev版本：这个版本用的是一个电位器加一个按钮来操作手表。但是这个设计不方便放进手表，体积会特别大，是明显不合适的。因为不考虑用这个版本做成品，因此此版本没有PCB。

2. 正式版本：这个版本用三个按钮操作手表（上，下，确定），更方便放进手表。这个版本有PCB。

   另外，这个版本取消了DS1302的备用电池，因为其体积实在太大且没什么实际用处。DS1302的布局从SOIC改成了DIP，主要是因为我手残不会焊SOIC。电阻也改成直插式了。
## 制作说明
可以直接用Arduino编译程序下载（如果用ESP8266裸板需要另买USB转串口线一根，把里面TXD和RXD插到裸板的RXD和TXD上），也可以下载已经编译好的bin文件（现在还没准备好）。但是如果需要修改Flash片内内容，则必须用Arduino手动编译。

## 修改片内Flash方法
1. 先参考libconfig文件夹中安装依赖库的说明，安装库和文件系统工具。
2. 在源代码的data文件夹下放置需要的文件。
3. 找到工具->ESP8266 Sketch Data Upload，点击即可上传。
