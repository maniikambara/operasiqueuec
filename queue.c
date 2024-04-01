#include <stdio.h>
#include <stdlib.h>

#define ukuran_max 100

typedef struct {
    int data[ukuran_max];
    int head, tail;
} queue;

void initQueue(queue *q) {
    q->head = q->tail = -1;
}

int isEmpty(queue *q) {
    return q->head == -1 && q->tail == -1;
}

int isFull(queue *q) {
    return q->tail == ukuran_max - 1;
}

void enqueue(queue *q, int nilai) {
    if (isFull(q)) {
        printf("Queue Penuh!\n");
        return;
    }
    if (isEmpty(q)) {
        q->head = q->tail = 0;
    } else {
        q->tail++;
    }
    q->data[q->tail] = nilai;
}

int dequeue(queue *q) {
    if (isEmpty(q)) {
        printf("Queue Kosong!\n");
        return -1;
    }
    int nilai = q->data[q->head];
    if (q->head == q->tail) {
        q->head = q->tail = -1;
    } else {
        q->head++;
    }
    return nilai;
}

void pencarian(queue *q, int nilai) {
    if (isEmpty(q)) {
        printf("Queue Kosong. Tidak bisa Mencari\n");
        return;
    }
    for (int i = q->head; i <= q->tail; i++) {
        if (q->data[i] == nilai) {
            printf("Elemen %d ditemukan didalam queue.\n", nilai);
            return;
        }
    }
    printf("Elemen %d tidak ditemukan didalam queue.\n", nilai);
}

void edit(queue *q, int nilailama, int nilaibaru) {
    if (isEmpty(q)) {
        printf("Queue Kosong. Tidak bisa Diedit.\n");
        return;
    }
    for (int i = q->head; i <= q->tail; i++) {
        if (q->data[i] == nilailama) {
            q->data[i] = nilaibaru;
            printf("Elemen %d telah diperbarui menjadi %d.\n", nilailama, nilaibaru);
            return;
        }
    }
    printf("Elemen %d tidak ditemukan didalam queue.\n", nilailama);
}

void hitung(queue *q) {
    if (isEmpty(q)) {
        printf("Queue Kosong. Tidak bisa Dikalkulasi.\n");
        return;
    }
    int sum = 0, max = q->data[q->head], min = q->data[q->head];
    for (int i = q->head; i <= q->tail; i++) {
        sum += q->data[i];
        if (q->data[i] > max) {
            max = q->data[i];
        }
        if (q->data[i] < min) {
            min = q->data[i];
        }
    }
    printf("Total : %d\n", sum);
    printf("Rata-rata : %.2f\n", (float)sum / (q->tail - q->head + 1));
    printf("Nilai Terbesar : %d\n", max);
    printf("Nilai Terkecil : %d\n", min);
}

int main() {
    queue q;
    initQueue(&q);

    int pilih, nilai, nilailama, nilaibaru;
    do {
        system("cls");
        printf("+-----------------------------------------+\n\n");
        printf("\t\tTUGAS QUEUE\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("\tOperasi Queue\n");
        printf("\t1. Enqueue (menambahkan elemen)\n");
        printf("\t2. Dequeue (mengeluarkan elemen)\n");
        printf("\t3. Cari Elemen\n");
        printf("\t4. Edit Elemen\n");
        printf("\t5. Kalkulasi Queue\n");
        printf("\t6. Keluar\n\n");
        printf("+-----------------------------------------+\n\n");
        printf("\tPILIHAN (1-6) : ");
        scanf("%d", &pilih);

        switch (pilih) {
            case 1:
                system("cls");
                printf("Masukkan nilai untuk ditambah pada Queue (enqueue) : ");
                scanf("%d", &nilai);
                enqueue(&q, nilai);
                system("pause");
                break;
            case 2:
                system("cls");
                nilai = dequeue(&q);
                if (nilai != -1) {
                    printf("Nilai %d telah Dikeluarkan (dequeued)\n", nilai);
                }
                system("pause");
                break;
            case 3:
                system("cls");
                printf("Masukkan nilai yang dicari : ");
                scanf("%d", &nilai);
                pencarian(&q, nilai);
                system("pause");
                break;
            case 4:
                system("cls");
                printf("Masukkan nilai lama yang akan diganti : ");
                scanf("%d", &nilailama);
                printf("Masukkan nilai baru : ");
                scanf("%d", &nilaibaru);
                edit(&q, nilailama, nilaibaru);
                system("pause");
                break;
            case 5:
                system("cls");
                hitung(&q);
                system("pause");
                break;
            case 6:
                printf("\n\tTerima kasih!\n");
                break;
            default:
                printf("Pilihan tidak valid...\n");
                system("pause");
        }
    } while (pilih != 6);

    return 0;
}