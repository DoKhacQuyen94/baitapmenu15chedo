#include<stdio.h>
int main(){
    int soPhanTu = 0;
    int arr[100];
    int choice;
    int position,giaTri;
    int count=0;
    int max1, max2;
    do{
        printf("\n----MENU-----\n");
        printf("1. Nhập số phần tử và giá trị cho mảng\n");
        printf("2. In phần tử trong mảng\n");
        printf("3. Đếm số lượng số hoàn hảo\n");
        printf("4. Tìm giá trị lớn thứ 2 trong mảng, không được sắp xếp mảng\n");
        printf("5. Thêm phần tử\n");
        printf("6. Xóa phần tử ở vị trí cụ thể\n");
        printf("7. Sắp xếp mảng theo thứ tự tăng dần (Insertion sort)\n");
        printf("8. Cho người dùng nhập vào một phần tử, tìm kiếm xem phần tử đó có tồn tại trong mảng hay không (Binary search)\n");
        printf("9. Sắp xếp lại mảng và hiển thị ra toàn bộ phần tử có trong mảng sao cho toàn bộ số chẵn đứng trước, số lẻ đứng sau\n");
        printf("10. Đảo ngược thứ tự của các phần tử có trong mảng\n");
        printf("11. Đếm số nguyên tố\n");
        printf("12. Tìm giá trị nhỏ thứ 2\n");
        printf("13. Sắp xếp mảng theo thứ tự giảm dần (Insertion sort)\n");
        printf("14. Xóa phần tử trùng lặp và in phần tử độc nhất\n");
        printf("15. Thoát\n");
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d",&choice);
        switch (choice){
            case 1:
                printf("Nhập số phần tử (1-100):");
                scanf("%d",&soPhanTu);
                if(soPhanTu < 0 || soPhanTu > 100){
                    printf("Nhập sai số rồi");
                    break;
                }
                for (int i = 0; i < soPhanTu; i++){
                    printf("Nhập phần tử thứ %d: ",i+1);
                    scanf("%d",&arr[i]);
                } 
                break;
            case 2:
                if (soPhanTu == 0){
                    printf("Mảng trống\n");
                    break;
                }
                printf("\n Phần tử trong mảng là: ");
                for (int i = 0; i < soPhanTu; i++)
                {
                    printf("%2d", arr[i]);
                } 
                break;
            case 3:
                for (int i = 0; i < soPhanTu; i++) {
                    int sum = 0;
                    for (int j = 1; j < arr[i]; j++) {
                        if (arr[i] % j == 0) {
                            sum += j;
                        }
                    }
                    if (sum == arr[i] && arr[i] > 0) {
                        count++;
                        printf("%d là số hoàn hảo.\n", arr[i]);
                    }
                }
                printf("\nSố lượng số hoàn hảo trong mảng: %d\n", count);
                break;
            case 4:
                if (arr[0] > arr[1]) {
                    max1 = arr[0];
                    max2 = arr[1];
                } else {
                    max1 = arr[1];
                    max2 = arr[0];
                }
                for (int i = 2; i < soPhanTu; i++) {
                    if (arr[i] > max1) {
                        max2 = max1;
                        max1 = arr[i];
                    } else if (arr[i] > max2 && arr[i] != max1) {
                        max2 = arr[i];
                    }
                }
                if (max1 == max2) {
                    printf("Mảng không có giá trị lớn thứ 2.\n");
                } else {
                    printf("Giá trị lớn thứ 2 trong mảng là: %d\n", max2);
                }
                break;
            case 5:
                printf("Nhập vị trí muốn thêm phần tử(1-%d): ",soPhanTu);
                scanf("%d",&position);
                printf("Nhập giá trị muốn thêm vào: ");
                scanf("%d",&giaTri);
                if (position < 0 || position > soPhanTu) {
                    printf("Vị trí không hợp lệ.\n");
                    break;
                }
                for(int i=soPhanTu ; i>position; i--){
                        arr[i]=arr[i-1];
                    }
                arr[position] = giaTri;
                soPhanTu++;
                printf("\nThêm phần tử thành công\n");
                break;
            case 6:
                printf("\nNhập vị trí cần xóa (từ 1 đến %d): ",soPhanTu);
                scanf("%d", &position);
                if (position < 0 || position > soPhanTu) {
                    printf("Vị trí không hợp lệ.\n");
                } else {
                    for (int i = position-1; i <= soPhanTu ; i++) {
                        arr[i] = arr[i + 1];
                    }
                    soPhanTu--;
                    printf("Đã xóa phần tử thành công.\n");
                }
                break;
            case 7:
                for(int i =1; i<soPhanTu; i++){
                    int key = arr[i];
                    int j;
                    for(j=i-1; j>=0&&arr[j]>key; j--){
                        arr[j+1]= arr[j];
                    }
                    arr[j+1]=key;
                }
                break;
            case 8:
                int start=0;
                int end =soPhanTu;
                int mid ;
                int check =-1;
                int searchValue;
                fflush(stdin);
                printf("Nhập phần tử cần tìm: ");
                scanf("%d",&searchValue);
                while (start<=end){
                    mid = (start+end)/2;
                    printf("%d",mid);
                    if(arr[mid]==searchValue){
                        printf("Phần tử tồn tại trong mảng tại vị trí: %d",mid);
                        check = 1;
                        break;
                    }else if (arr[mid]<searchValue){
                        start = mid+1;
                    }else{
                        end = mid -1;
                    }     
                }
                if (check != 1){
                    printf("Không tìm thấy phần tử trong mảng\n");
                }
                break;
            case 9:
                for (int i = 0; i < soPhanTu - 1; i++) {
                    for (int j = i + 1; j < soPhanTu; j++) {
                        // Đổi chỗ nếu phần tử đầu là số lẻ và phần tử sau là số chẵn
                        if (arr[i] % 2 != 0 && arr[j] % 2 == 0) {
                            int temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                printf("\nMảng sau khi sắp xếp (số chẵn đứng trước, số lẻ đứng sau):\n");
                for (int i = 0; i < soPhanTu; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;
            case 10:
                for (int i = 0; i < soPhanTu / 2; i++) {
                    int temp = arr[i];
                    arr[i] = arr[soPhanTu - i - 1];
                    arr[soPhanTu - i - 1] = temp;
                }
                printf("Đảo thành công\n");
                break;
            case 11:
                for (int i = 0; i < soPhanTu; i++) {
                    int isPrime = 1;
                    if (arr[i] < 2) {
                        isPrime = 0; 
                    } else {
                        for (int j = 2; j <= arr[i] / 2; j++) { 
                            if (arr[i] % j == 0) {
                                isPrime = 0;
                                break;
                            }
                        }
                    }
                    if(isPrime){
                        count++;
                    }
                }
                printf("Số lượng số nguyên tố trong mảng là: %d\n", count);
                break;
            case 12:
                int min1 = arr[0];
                int min2 = arr[0];
                int found = 0; 
                for (int i = 1; i < soPhanTu; i++) {
                    if (arr[i] < min1) {
                        min1 = arr[i];
                    }
                }
                for (int i = 0; i < soPhanTu; i++) {
                    if (arr[i] > min1) {
                        if (found ==0 || arr[i] < min2) {
                            min2 = arr[i];
                            found = 1; 
                        }
                    }
                }
                if (found == 0) {
                    printf("Không tồn tại giá trị nhỏ thứ 2 trong mảng.\n");
                } else {
                    printf("Giá trị nhỏ thứ 2 trong mảng: %d\n", min2);
                }  
                break;
            case 13:
                for (int i = 1; i < soPhanTu; i++) {
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key) {
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Sắp xếp mảng giảm dần thành công\n");
                break;
            case 14:
                for (int i = 0; i < soPhanTu; i++) {
                    for (int j = i + 1; j < soPhanTu; j++) {
                        if (arr[i] == arr[j]) {
                            for (int k = j; k < soPhanTu - 1; k++) {
                                arr[k] = arr[k + 1];
                            }
                            soPhanTu--;    
                            j--; 
                        }
                    }
                }

                break;
            case 15:
                printf("Bạn đã thoát");
                break;
            default:
                printf("Bạn chọn sai rồi");
                break;
            }
    } while (choice != 15);
    return 0;
}