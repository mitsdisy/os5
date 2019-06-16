#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"

#include "discs.h"
#include "documents.h"
#include "catalogues.h"

int main(int argc, char* argv[])
{
    initDisk();
    
	initDic();

	int n;
	int res;
    int len;

    char name[28];

    char str[512];
    
	FILES* f;

	printf("\n");
   
	printf("1.创建一个新的文件\n");

	printf("2.删除一个文件\n");
	printf("3.打开一个文件\n");
    printf("4.关闭一个文件\n");
    printf("5.读取一个文件\n");
    printf("6.写入一个文件\n");
    printf("输入你想要的功能：");
 
	
       
		scanf("%d", &n);
        
		switch (n) 
		{
            
			case 1:     
				//创建一个新的文件
                printf("请输入新的文件名称:");
                scanf("%s", name);
                create(name);
                break;       
	    case 2:  
                printf("请输入你想要删除的文件名称:");
                scanf("%s", name);
                res = destroy(name);
                break;   
		
            case 3:     
				//打开一个文件
               printf("请输入想要打开的文件名称:");
                scanf("%s", name);
                f = open(name);
                if(f != NULL)
                {
                    printf("%s打开成功！\n",name);
                }
                break;
 
	
            case 4:     
                printf("请输入文想要关闭的文件名称:");
                scanf("%s", name);
                f = open(name);
                if(f == NULL)
                {
                    break;
                }
                close(f);
                break;
	
                
            case 5:      
                printf("请输入想要读入的文件名称:");
                scanf("%s", name);
                f = open(name);

                if(f == NULL)
                {
                    break;
                }
                printf("请输入读入内容的长度:");
                scanf("%d", &len);
                str[0] = '\0';
                f = read(f, str, len);
                if(f == NULL)
                {
                    printf("长度越界\n");
                }
                printf("%s\n", str);

                break;           
            case 6:     
	  
				//写文件
                printf("请输入想要写入的文件名称:");
                scanf("%s", name);
                f = open(name);

                if(f == NULL)
                {
                    break;
                }
                printf("请输入想要写入内容:");
                scanf("%s", str);
                printf("请输入想要写入的长度:");
                scanf("%d", &len);
                f = write(f, str, len);

                break;
                     default:
				break;
        }

		fflush(stdin);
    
}