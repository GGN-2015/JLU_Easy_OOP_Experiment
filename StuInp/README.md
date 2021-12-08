# StuInp 傻了吧唧的解释性语言

感觉实现一个正经解释器还是太难了，先实现一个 ``傻了吧唧`` 的解释型语言再说。

## 基本语法

一个文件就是一个函数，文件名就是函数名，文件后缀名为 ``.stu``，只支持整数类型变量。

### 获取参数表 ARGU

```basic
ARGU <name_1> ... <name_n> '将函数参数装载到对应的变量中去,如果参数个数不匹配则报错
```

### 定义变量 VAR, ARRAY

```basic
VAR <name_1> ... <name_n> '如果重复定义了一个名字，问题不大，新的变量会覆盖旧的，变量都是 int32 类型
ARRAY <name> ( length_exp ) '数组长度用一个表达式描述
```

### 输入输出 PRINT, INPUT

```basic
PRINT <name_1> ... <name_n> '截取 int32 的低八位，输出对应的字符
INPUT <name_1> ... <name_n> '将输入的字符赋值给变量
```

### 表达式计算 SET

& 表示取一个名字对应的地址，等号左侧必须填入一个地址。

```basic
SET & <name> = ( exp ) '此处填入符合规范的表达式
```

```basic
SET <addr> =  ( exp ) '表达式
```

表达式语法：

```
'没有优先级，支持 + - * / %, 具体计算顺序取决于括号
'指出函数调用 FUNC funcName ( ( <exp_1> ) ... ( <exp_n> ) )
```

### 条件判断 IF

```basic
IF ( exp ) ' 判断表达式的结果是不是零
    ...
ELSE
    ...
END
```

### 循环 WHILE

```basic
WHILE ( exp ) '判断结果不是零
	...
    BREAK    '提前结束循环
    CONTINUE '直接跳到开头重新检查 exp 是否满足条件
END
```

### 返回语句 RETURN

```basic
RETURN ( exp ) '返回结果一定是整数
```

