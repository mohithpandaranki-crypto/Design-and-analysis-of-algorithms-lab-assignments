#include <stdio.h>
#include <string.h>

#define N    9
#define MAXN (2 * N - 1)

typedef struct {
    int  freq;
    char ch;
    int  left, right;
    int  active;
} Node;

Node tree[MAXN];
int  cnt = 0;
char codes[N][16];

int pick_min(void) {
    int best = -1;
    for (int i = 0; i < cnt; i++)
        if (tree[i].active && (best == -1 || tree[i].freq < tree[best].freq))
            best = i;
    return best;
}

void label(int i, char *out) {
    if (tree[i].ch) sprintf(out, "%c", tree[i].ch);
    else            sprintf(out, "(%d)", tree[i].freq);
}

void build_huffman(void) {
    int step = 1;
    for (int k = 0; k < N - 1; k++) {
        int a = pick_min(); tree[a].active = 0;
        int b = pick_min(); tree[b].active = 0;

        char la[8], lb[8];
        label(a, la); label(b, lb);
        int sum = tree[a].freq + tree[b].freq;
        printf("Step %d: merge %s:%d + %s:%d -> new node %d\n",
               step++, la, tree[a].freq, lb, tree[b].freq, sum);

        tree[cnt].freq = sum;  tree[cnt].ch = 0;
        tree[cnt].left = a;    tree[cnt].right = b;
        tree[cnt].active = 1;  cnt++;
    }
}

void get_codes(int i, char *buf, int depth) {
    if (tree[i].ch) {
        buf[depth] = '\0';
        strcpy(codes[i], buf);
        return;
    }
    buf[depth] = '0'; get_codes(tree[i].left,  buf, depth + 1);
    buf[depth] = '1'; get_codes(tree[i].right, buf, depth + 1);
}

void print_tree(int i, int depth, char bit) {
    for (int s = 0; s < depth; s++) printf("  ");
    if (depth > 0) printf("%c-> ", bit);
    if (tree[i].ch) printf("%c:%d\n", tree[i].ch, tree[i].freq);
    else            printf("%d\n", tree[i].freq);
    if (!tree[i].ch) {
        print_tree(tree[i].left,  depth + 1, '0');
        print_tree(tree[i].right, depth + 1, '1');
    }
}

int main(void) {
    char letters[N] = {'a', 'c', 'd', 'e', 'o', 'm', 's', 't', 'u'};
    int  freqs[N]   = { 20,  11,   2,  10,  15,   8,  10,  22,   2};   /* in hundreds */

    for (int i = 0; i < N; i++) {
        tree[i].freq = freqs[i];  tree[i].ch = letters[i];
        tree[i].left = tree[i].right = -1;
        tree[i].active = 1;
    }
    cnt = N;

    build_huffman();
    int root = cnt - 1;

    char buf[16];
    get_codes(root, buf, 0);

    printf("\nTree (0 = left, 1 = right):\n");
    print_tree(root, 0, ' ');

    /* order rows by code length, then alphabetically */
    int order[N];
    for (int i = 0; i < N; i++) order[i] = i;
    for (int i = 0; i < N - 1; i++)
        for (int j = 0; j < N - 1 - i; j++) {
            int x = order[j], y = order[j + 1];
            int lx = strlen(codes[x]), ly = strlen(codes[y]);
            if (lx > ly || (lx == ly && letters[x] > letters[y])) {
                order[j] = y; order[j + 1] = x;
            }
        }

    printf("\nLetter  Freq  Code    Bits\n");
    long total_bits = 0;
    int  total_chars = 0;
    for (int k = 0; k < N; k++) {
        int i = order[k];
        long bits = (long)freqs[i] * 100 * strlen(codes[i]);
        total_bits  += bits;
        total_chars += freqs[i] * 100;
        printf("  %c     %4d  %-6s  %ld\n", letters[i], freqs[i] * 100, codes[i], bits);
    }

    printf("\nTotal bits  = %ld\n", total_bits);
    printf("Total bytes = %.1f\n", total_bits / 8.0);
    printf("Fixed-length (4 bits/letter) = %d bits\n", total_chars * 4);
    return 0;
}