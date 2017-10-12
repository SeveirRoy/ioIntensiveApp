#include <libc\stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

void *ioThreadFunction1();
void *ioThreadFunction2();
void *ioThreadFunction3();
void *ioThreadFunction4();
void *ioThreadFunction5();
void *ioThreadFunction6();
void *ioThreadFunction7();
void *ioThreadFunction8();


void createFourFile();

int main()
{
    int res1;
    int res2;
    int res3;
    int res4;
    int res5;
    int res6;
    int res7;
    int res8;


    void *thread_result1;
    void *thread_result2;
    void *thread_result3;
    void *thread_result4;
    void *thread_result5;
    void *thread_result6;
    void *thread_result7;
    void *thread_result8;
    
    pthread_t ioThread1;
    pthread_t ioThread2;
    pthread_t ioThread3;
    pthread_t ioThread4;
    pthread_t ioThread5;
    pthread_t ioThread6;
    pthread_t ioThread7;
    pthread_t ioThread8;
    
    createFourFile();

    res1 = pthread_create(&ioThread1, NULL, ioThreadFunction1, NULL);
    res2 = pthread_create(&ioThread2, NULL, ioThreadFunction2, NULL);
    res3 = pthread_create(&ioThread3, NULL, ioThreadFunction3, NULL);
    res4 = pthread_create(&ioThread4, NULL, ioThreadFunction4, NULL);   
    res5 = pthread_create(&ioThread5, NULL, ioThreadFunction5, NULL);
    res6 = pthread_create(&ioThread6, NULL, ioThreadFunction6, NULL);
    res7 = pthread_create(&ioThread7, NULL, ioThreadFunction7, NULL);
    res8 = pthread_create(&ioThread8, NULL, ioThreadFunction8, NULL); 

    if(res1 != 0){
        printf("Error: failed to create ioThread1!\n");
    }
    else{
        printf("Note: successfully created ioThread1!\n");
    }

    if(res2 != 0){
        printf("Error: failed to create ioThread2!\n");
    }
    else{
        printf("Note: successfully created ioThread2!\n");
    }

    if(res3 != 0){
        printf("Error: failed to create ioThread3!\n");
    }
    else{
        printf("Note: successfully created ioThread3!\n");
    }

    if(res4 != 0){
        printf("Error: failed to create ioThread4!\n");
    }
    else{
        printf("Note: successfully created ioThread4!\n");
    }
    
    if(res5 != 0){
        printf("Error: failed to create ioThread5!\n");
    }
    else{
        printf("Note: successfully created ioThread5!\n");
    }

    if(res6 != 0){
        printf("Error: failed to create ioThread6!\n");
    }
    else{
        printf("Note: successfully created ioThread6!\n");
    }

    if(res7 != 0){
        printf("Error: failed to create ioThread7!\n");
    }
    else{
        printf("Note: successfully created ioThread7!\n");
    }

    if(res8 != 0){
        printf("Error: failed to create ioThread8!\n");
    }
    else{         
        printf("Note: successfully created ioThread8!\n");
    }


    printf("Note: waiting for all ioThreads to finish!\n");    
    
    res1 = pthread_join(ioThread1, &thread_result1);
    res2 = pthread_join(ioThread2, &thread_result2);
    res3 = pthread_join(ioThread3, &thread_result3);
    res4 = pthread_join(ioThread4, &thread_result4);
    res5 = pthread_join(ioThread5, &thread_result5);
    res6 = pthread_join(ioThread6, &thread_result6);
    res7 = pthread_join(ioThread7, &thread_result7);
    res8 = pthread_join(ioThread8, &thread_result8);

    
    if(res1 != 0 && res2 != 0 && res3 != 0 && res4 != 0 && res5 != 0 && res6 != 0 && res7 != 0 && res8 != 0){
        printf("Note: successfully exit this program!\n");
    }    

    return 0;

}

void createFourFile()
{
    FILE *file1;
    FILE *file2;
    FILE *file3;
    FILE *file4;
    FILE *file5;
    FILE *file6;
    FILE *file7;
    FILE *file8;


    file1 = fopen("./test_file1", "w+");
    file2 = fopen("./test_file2", "w+");
    file3 = fopen("./test_file3", "w+");
    file4 = fopen("./test_file4", "w+");
    file5 = fopen("./test_file5", "w+");
    file6 = fopen("./test_file6", "w+");
    file7 = fopen("./test_file7", "w+");
    file8 = fopen("./test_file8", "w+");


    int size = 50000000;
    while(size > 0){
        fputc('a', file1);
        fputc('a', file2);
        fputc('a', file3);
        fputc('a', file4);
        fputc('a', file5);
        fputc('a', file6);
        fputc('a', file7);
        fputc('a', file8);
        size--;
    }
    fclose(file1);
    fclose(file2);
    fclose(file3);
    fclose(file4);
    fclose(file5);
    fclose(file6);
    fclose(file7);
    fclose(file8);

    
    printf("NOTE: test_files have been created!\n");    

    return;
}

void *ioThreadFunction1()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file1", "r");
    fileOut = fopen("./test_file1_out", "w+");
    
    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }   
        fclose(fileIn);
        fclose(fileOut);
        
        fileIn = fopen("./test_file1", "r");
        fileOut = fopen("./test_file1_out", "w+");
        times--;
    }   

}

void *ioThreadFunction2()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file2", "r");
    fileOut = fopen("./test_file2_out", "w+");

    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }
        fclose(fileIn);
        fclose(fileOut);

        fileIn = fopen("./test_file2", "r");
        fileOut = fopen("./test_file2_out", "w+");
        times--;
    }
}

void *ioThreadFunction3()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file3", "r");
    fileOut = fopen("./test_file3_out", "w+");

    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }
        fclose(fileIn);
        fclose(fileOut);

        fileIn = fopen("./test_file3", "r");
        fileOut = fopen("./test_file3_out", "w+"); 
        times--;
    }
}

void *ioThreadFunction4()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file4", "r");
    fileOut = fopen("./test_file4_out", "w+");

    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }
        fclose(fileIn);
        fclose(fileOut);

        fileIn = fopen("./test_file4", "r");
        fileOut = fopen("./test_file4_out", "w+"); 
        times--;
    }
}

void *ioThreadFunction5()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file5", "r");
    fileOut = fopen("./test_file5_out", "w+");

    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }
        fclose(fileIn);
        fclose(fileOut);

        fileIn = fopen("./test_file5", "r");
        fileOut = fopen("./test_file5_out", "w+");
        times--;
    }
}

void *ioThreadFunction6()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file6", "r");
    fileOut = fopen("./test_file6_out", "w+");

    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }
        fclose(fileIn);
        fclose(fileOut);

        fileIn = fopen("./test_file6", "r");
        fileOut = fopen("./test_file6_out", "w+");
        times--;
    }
}

void *ioThreadFunction7()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file7", "r");
    fileOut = fopen("./test_file7_out", "w+");

    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }
        fclose(fileIn);
        fclose(fileOut);

        fileIn = fopen("./test_file7", "r");
        fileOut = fopen("./test_file7_out", "w+");
        times--;
    }
}

void *ioThreadFunction8()
{
    char buff1[1025];
    int times = 500000000;
    FILE *fileIn;
    FILE *fileOut;
    fileIn = fopen("./test_file8", "r");
    fileOut = fopen("./test_file8_out", "w+");

    while(times > 0){
        while(fgets(buff1, 1024, fileIn) != NULL){
            fputs(buff1, fileOut);
        }
        fclose(fileIn);
        fclose(fileOut);

        fileIn = fopen("./test_file8", "r");
        fileOut = fopen("./test_file8_out", "w+");
        times--;
    }
}

