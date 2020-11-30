package sort;
import java.lang.Math;
import java.util.Random;

public class QuickSort {
    public static void main(String[] args) {
        Object[] v = {1, 3, 2, -30, 9, 5};
        quicksort(v, 0, v.length - 1, new IntegerComparator());
        //System.out.println(v);
        for (int i = 0; i < v.length; i++)
            System.out.print(v[i] + " ");
            System.out.println();
    }
    public static void quicksort(Object[] v, int left, int right, Comparator cmp) {
        int i, last;
        if (left >= right) return;
        swap(v, left, rand(left, right));
        last = left;
        for (i = left + 1; i <= right; i++) 
            if (cmp.compare(v[i], v[left]) < 0)
                swap(v, ++last, i);
        swap(v, left, last);
        quicksort(v, left, last - 1, cmp);
        quicksort(v, last + 1, right, cmp);
    }
    static void swap(Object[] v, int i, int j) {
        Object temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    static Random rgen = new Random();
    static int rand(int left, int right) {
        return left + Math.abs(rgen.nextInt()) % (right - left);
    }
} 