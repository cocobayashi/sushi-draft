#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int Mypack[15];                       //神話 2 種類 レア 5 種類 アンコモン 7 種類 コモン 9 種類
    int pack[15][4];
    int cade[249];
    int i;
    int j;
    int k;
    int temp;
    int temp1;
    int scan;
    int flag;
    int Mysushi[15];

    for (i = 0; i < 4; i++) {                           //寿司パックを計４パック作成
        for (j = 0; j < 15; j++) {                     //寿司パック作成
            do {                                    
                flag = 0;
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
                        flag = 1;
                    }
                }       
            } while (flag == 1);                        //チェック
            pack[j][i] = temp;                             //パックにネタの情報を入れる
        }
    }


    for (i = 0; i < 15; i++) {
        printf(" %d pick目\n", i + 1);
        temp = i % 4;
        for (j = 0; j < 15; j++) {
            if (pack[j][temp] != -1){
                printf("%d ",j + 1);
                switch (pack[j][temp]) {
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
                if (j < 14) {
                    printf("、");
                } else {
                    printf("\n");
                }
            }
        }
        printf("\n");
        printf("ネタを選んで下さい。(数字で入力してください。)\n");
        printf("==> ");
        scanf("%d", &scan);
        do {
            scan -= 1;
            flag = 0;
            if (scan > 14 || scan < 0) {
                printf("エラー 0 ~ 15 の間で入力して下さい。\n");
                printf("\n");
                printf("ネタを選んで下さい。(数字で入力してください。)\n");
                printf("==> ");
                scanf("%d", &scan);
                flag = 1;
            } else if (pack[scan][temp] == -1){
                printf("エラー 選んだネタはすでにpickされています。\n");
                printf("\n");
                printf("ネタを選んで下さい。(数字で入力してください。)\n");
                printf("==> ");
                scanf("%d", &scan);
                flag = 1;
            }
        } while (flag == 1);
        Mysushi[i] = pack[scan][temp];
        pack[scan][temp] = -1;

        for (j = 0; j < 4; j++) {                           //pick中以外のパックからランダムにネタを抜くループ
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
    for (i = 0; i < 15; i++) {
        printf("%d、%d", i, Mysushi[i]);
    }
    return 0;
}