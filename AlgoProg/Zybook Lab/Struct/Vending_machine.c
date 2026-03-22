#include <stdio.h>

#include "VendingMachine.h"

int main()
{
    int x;
    VendingMachine vends = InitVendingMachine();

    scanf("%d", &x);
    vends = Purchase(x, vends);

    scanf("%d", &x);
    vends = Restock(x, vends);

    scanf("%d", &x);
    vends = Purchase(x, vends);

    Report(vends);

    return 0;
}