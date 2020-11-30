package sort;

interface Comparator {
    int compare(Object x, Object y);
}

class IntegerComparator implements Comparator {
    public int compare(Object o1, Object o2) {
        int i1 = ((Integer)o1).intValue();
        int i2 = ((Integer)o2).intValue();
        if (i1 < i2) 
            return -1;
        else if (i1 == i2)
            return 0;
        else
            return 1;
    }
}

class StringComparator implements Comparator {
    public int compare(Object o1, Object o2) {
        String s1 = (String)o1;
        String s2 = (String)o2;
        return s1.compareTo(s2);
    }
}