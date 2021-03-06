#include <stdio.h>
#include <stdlib.h>

int input(void);
void output(pack);

int main(void)
{          
    int Mypack[15];
    int pack[15][5];                        //パック 15はパックの中身数を表す  1~4はドラフトパック 5は自分がpickしたパック 
    int i;                                  //ループカウンタ
    int j;                                  //ループカウンタ
    int k;                                  //ループカウンタ
    int temp;                               //作業領域
    int temp1;                              //作業領域１
    int scan;                               //入力
    int flag;                               //フラグ

    for (i = 0; i < 4; i++) {                           //寿司パックを計４パック作成   神話 2 種類 レア 5 種類 アンコモン 7 種類 コモン 9 種類
        for (j = 0; j < 15; j++) {                      //寿司パック作成ループ
            do {                                    
                flag = flag & 0x0;
                if (j == 0) {
                    temp = 0 + rand() % 2;              //神話レアのネタ 2 種類の抽選
                } else if (j <= 3){
                    temp = 0 + rand() % 5 + 2;          //レアのネタ 5 種類の抽選
                } else if (j <= 7) {
                    temp = 0 + rand() % 7 + 7;          //アンコモンのネタ 7 種類の抽選
                } else {
                    temp = 0 + rand() % 9 + 14;         //コモンのネタ 9 種類の抽選
                }
                for (k = 0; k < j; k++) {               
                    if (temp == pack[k][i]) {          //パック内に同じネタが存在する場合 flag = 1(エラー)でやり直し
                        flag = flag | 0x1;
                    }
                }       
            } while ((flag & 0x1) == 0x1);                        //チェック

            pack[j][i] = temp;                             //パックにネタの情報を入れる      
        }
    }


    for (i = 0; i < 15; i++) {                          //pick(１５回)   
            printf(" %d pick目\n", i + 1);
            temp = i % 4;

        for (j = 0; j < 15; j++) {                      //pickするパック内を表示
            if (pack[j][temp] != -1){                   //パック内に存在しないのは表示しない
                printf("%d ",j + 1);
                output (pack[j][temp]);
                  
                if (j < 14) {
                    printf("、");
                } else {
                    printf("\n");
                }
            }
        }

        printf("\n");
        scan = input();

        do {                                                    //エラーチェック
            scan -= 1;
            flag = 0;
            if (scan > 14 || scan < 0) {
                printf("エラー 0 ~ 15 の間で入力して下さい。\n");
                printf("\n");
                scan = input();
                flag = 1;
            } else if (pack[scan][temp] == -1){
                printf("エラー 選んだネタはすでにpickされています。\n");
                printf("\n");
                scan = input();
                flag = 1;
            }
        } while (flag == 1);

        Mypack[i] = pack[scan][temp];
        pack[scan][temp] = -1;                                  // -1 = パック内が空

        for (j = 0; j < 4; j++) {                           //pick中以外のパックからランダムにネタを抜くループ
            if (i == 14) {
                break;
            }
            if (temp == 0 && j == 0) {

            } else if (temp == 3 && j == 1) {

            } else if (temp == 2 && j == 2) {

            } else if (temp == 1 && j == 3) {

            } else {
                do {
                    flag = 0;
                    temp1 = 0 + rand() % 15;
                        if (pack[temp1][j] == -1) {
                            flag = 1;
                        }
                } while (flag == 1);

                pack[temp1][j] = -1;
            }
        }
    }

    printf("あなたがpickしたネタは…\n");
    for (i = 0; i < 15; i++){
        printf("%2d pick目 ",i + 1);
        output (Mypack[i]);
        printf("\n");
    }
    return 0;
}

int input (void)
{
    int scan;

    printf("ネタを選んで下さい。(数字で入力してください。)\n");
    printf("==> ");
    scanf("%d", &scan);

    return scan;
}

void output (pack)
{
    switch (pack){
        case 0:
            printf("大トロ");
            break;
        case 1:
            printf("ウニ&いくら");
            break;
        case 2:
            printf("赤エビ");
            break;
        case 3:
            printf("煮穴子");
            break;
        case 4:
            printf("中とろ");
            break;
        case 5:
            printf("寒ブリ");
            break;
        case 6:
            printf("甘鯛");
            break;
        case 7:
            printf("アジ");
            break;
        case 8:
            printf("マグロ");
            break;
        case 9:
            printf("サーモン");
            break;
        case 10:
            printf("いか");
            break;
        case 11:
            printf("タコ");
            break;
        case 12:
            printf("エビ");
            break;
        case 13:
            printf("ホタテ");
            break;
        case 14:
            printf("かっぱ巻き");
            break;
        case 15:
            printf("かんぴょう巻き");
            break;
        case 16:
            printf("いなり");
            break;
        case 17:
            printf("玉子焼き");
            break;
        case 18:
            printf("ナス");
            break;
        case 19:
            printf("納豆巻き");
            break;
        case 20:
            printf("新香巻き");
            break;
        case 21:
            printf("ハンバーグ");
            break;
        case 22:
            printf("コーン");
            break;
    }
                   
}