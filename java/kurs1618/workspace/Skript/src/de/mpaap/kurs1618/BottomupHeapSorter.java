package de.mpaap.kurs1618;

import java.util.Arrays;

public class BottomupHeapSorter
{
    private int[] a;
    private int n;

    public void sort(int[] a)
    {
        this.a=a;
        System.out.println("Retrieved following array: " + Arrays.toString(a));
        n=a.length;
        bottomupheapsort();
    }

    private void bottomupheapsort()
    {
        System.out.println("Sorting...");
        int x, u;
        buildheap();
        while (n>1)
        {
            n--;
            x=a[n];    // Marking the last leaf 
            a[n]=a[0];
            u=holedownheap();
            upheap(u, x);
        }
    }

    private void buildheap()
    {
        for (int v=n/2-1; v>=0; v--)
            downheap (v);
    }

    private void downheap(int v)
    {
        int w=2*v+1;         // 1st child of v
        while (w<n)
        {
            if (w+1<n)       // is there a 2nd one?
                if (a[w+1]>a[w]) w++;
            // w is child of v with max marker

            if (a[v]>=a[w]) return;  // v is Heap
            // else
            exchange(v, w);  // exchange Marker of v and w
            v=w;             // continue with v=w
            w=2*v+1;
        }
    }

    private int holedownheap()
    {
        int v=0, w=2*v+1;

        while (w+1<n)     // there is a 2nd child
        {
            if (a[w+1]>a[w]) w++;
            // w is child of v with max marker
            a[v]=a[w];
            v=w; w=2*v+1;
        }

        if (w<n)    // single leaf
        {
            a[v]=a[w];
            v=w;
        }
        // freigewordene Position ist an einem Blatt angekommen
        return v;
    }

    private void upheap(int v, int x)
    {
        int u;
        a[v]=x;
        while (v>0)
        {
            u=(v-1)/2;    // parent
            if (a[u]>=a[v]) return;
            // else
            exchange(u, v);
            v=u;
        }
    }

    private void exchange(int i, int j)
    {
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
    
    public void print() {
        if(a==null) {
            System.out.println("No elements.");
        } else {
            System.out.println("Sorted array:" + Arrays.toString(a));
        }
    }


    public static void main(String[] args) {
        BottomupHeapSorter test = new BottomupHeapSorter();
        test.sort(new int[] {60, 15, 23,16, 71, 98, 78, 72, 4});
        test.print();
    }

}    // end class BottomupHeapSorter

