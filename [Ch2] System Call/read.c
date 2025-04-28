#include <stdio.h>      // printf
#include <unistd.h>     // read, open, close
#include <fcntl.h>      // open
#include <stdlib.h>     // malloc, free

int main()
{
    int fd;
    char* buf;

    fd = open("text.txt", O_RDONLY);
    buf = (char*)malloc(sizeof(char) * 30);

    printf("1) read 반환값 : %zd\n", read(fd, buf, 10));
    printf("buf의 결과 : %s\n", buf);

    printf("2) read 반환값 : %zd\n", read(fd, buf, 10));
    printf("buf의 결과 : %s\n", buf);

    
    free(buf);
    close(fd);

    return 0;
}

/*------------------------------ 실행 결과 ------------------------------*/
/*                                                                      */
/*  1) read 반환값 : 10                                                  */
/*  buf의 결과 : Hello, Wor                                              */
/*  2) read 반환값 : 3                                                   */
/*  buf의 결과 : ld!lo, Wor                                              */
/*                                                                      */
/*  read 함수 호출 시,                                                    */
/*  1글자 읽을 때마다 fd 증가 + buf 는 배열의 처음 위치로 초기화               */
/*                                                                      */
/*----------------------------------------------------------------------*/