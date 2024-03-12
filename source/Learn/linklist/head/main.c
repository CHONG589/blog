#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main () {

    list *l;
    int i, err;
    datatype arr[] = {12, 4, 23, 1, 34, 45, 56};

    l = list_create ();
    if (l == NULL)
        exit (1);

    for (i = 0; i < (sizeof (arr) /sizeof (*arr)); i++){
        // ��������û��β 0 ��һ˵�����ַ��������
        if (list_order_insert (l, &arr[i])){
            exit (1);
        }
    }

    list_display (l);

    // list_delete (l, &arr[0]);

    // list_display (l);

    datatype value;
    err = list_delete_at (l, 2, &value);
    // err Ϊ 0 ʱ��˵���ɹ��ˣ�0 Ϊ��
    if (err) {
        exit (1);
    }
    list_display (l);
    printf ("delete:%d\n", value);

    list_destroy (l);

    exit (0);
}