package sort;
import java.lang.Math;
import java.util.Random;

public class QuickSort {
    public static void main(String[] args) {
        int[] v = {1, 3, 2};
        quicksort(v);
        System.out.println(v);
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
        sort(v, left, last - 1, cmp);
        sort(v, last + 1, right, cmp);
    }
    static void swap(Object[] v, int i, int j) {
        Object temp;
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
    static Random rgen = new Random();
    static void rand(int left, int right) {
        return left + Math.abs(rgen.nextInt()) % (right - left);
    }
} 