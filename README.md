# RestWall

**测试用的时间是5s**切换一次

### 2018-12-27

1. 时间倒计时，触发锁屏窗口弹出，全屏；
2. 锁屏窗口添加鼠标时间，右击弹出对话框，确认是否用户关闭；
3. 添加“开始”“暂停”按钮，通过点击“开始”启动倒计时；

---

### 2018-12-28

1. 添加锁屏窗口图片
2. 添加最小化托盘

---

### 2018-12-29

1. 由于之前窗口退出后，程序也退出，添加了 a.setQuitOnLastWindowClosed(false); 但是这样程序就没法通过点击右上角X退出程序了

2. 添加托盘的菜单，添加了退出程序的Action，一旦点击发送给主程序信号，主程序退出。

3. 添加QSettings读写ini文件，但是QSetting的目录在release的文件夹下，而不是在项目文件夹下，所以要复制过去。

4. 数字修改后，应用按钮点击可以将设置的数据写入ini文件中保存。

5. “取消”按钮点击，修改还没保存的数据会回复到之前的

6. release的exe文件添加了图标，只要在pro文件中加入一条RC_ICONS + = /images/cup.ico

   ---
