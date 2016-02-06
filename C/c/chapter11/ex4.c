void swap(int *p, int *q)
{
    int temp;
    temp = *p;
    *q = temp;
    *p = *q; //alternativ p = q; ?
}
