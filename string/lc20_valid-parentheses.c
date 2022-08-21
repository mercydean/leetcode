/*
 * @problem		https://leetcode.cn/problems/valid-parentheses/
 * @solution	https://leetcode.cn/problems/valid-parentheses/solution/you-xiao-de-gua-hao-by-leetcode-solution/
 * @brief		借助栈进行操作， 注意不要使用全局变量否则会出错（栈结构体的值被改写。）.可能leetcode的评估的系统会改写全局变量区。
 */
 
#define __DEBUG
//#undef __DEBUG

#ifdef __DEBUG
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__) 
#else
#define DEBUG(fmt, ...) 
#endif

struct stack{
    char buffer[10000];
    int length;
    int num;
    int top;
    int bottom;
};//满递增.



struct stack g_stack = {
    .num = 0,
    .length = 10000,
    .top = 10000 - 1,//.top = length - 1是错误的.
    .bottom = 0,
};

int push(char *chr)
{
    if(g_stack.num < g_stack.length)
    {
        DEBUG("push\n");
        g_stack.top = (g_stack.top+1)%g_stack.length;
        g_stack.buffer[g_stack.top] = *chr;
        g_stack.num++;
        DEBUG("num: %d\n", g_stack.num);
        return 0;
    }
    return -1;
}

int pop(char *chr)
{
    if(g_stack.num > 0)
    {
        DEBUG("pop\n");
        *chr = g_stack.buffer[g_stack.top];
        g_stack.top = (g_stack.top - 1)%g_stack.length;
        g_stack.num--;
        DEBUG("num: %d\n", g_stack.num);
        return 0;
    }
    return -1;
}

int stack_num()
{
    return g_stack.num;
}

bool isValid(char * s){
    char chr;
    
    DEBUG("num: %d\n", g_stack.num);//不知道为啥提交是1本地测试是0.
    DEBUG("length: %d\n", g_stack.length);
    DEBUG("top: %d\n", g_stack.top);
    DEBUG("bottom: %d\n", g_stack.bottom);

    g_stack.num = 0;

    for(int i = 0; *(s+i) != '\0'; i++)
    {
        if(*(s+i) == ')')
        {
            if(pop(&chr) == -1) return false;
            DEBUG("pop: %c\n", chr); 
            if(chr != '(') return false;
        }
        else if(*(s+i) == ']')
        {
            if(pop(&chr) == -1) return false;
            DEBUG("pop: %c\n", chr); 
            if(chr != '[') return false;
        }
        else if(*(s+i) == '}')
        {
            if(pop(&chr) == -1) return false;
            DEBUG("pop: %c\n", chr); 
            if(chr != '{') return false;
        }
        else
        {
            push(s+i);
        }
    }

    DEBUG("stack num:%d", stack_num());
    if(stack_num() == 0) return true;

    else
        return false;
}