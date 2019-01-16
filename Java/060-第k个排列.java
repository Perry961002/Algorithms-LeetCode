class Solution {
    public String getPermutation(int n, int k) {
        List<Integer> b = new ArrayList<>();
        int a[] = new int[n];
        int j = 0;

        for (int i = 0; i <= n; i++) {
            b.add(i);
        }

        for (int i = n; i > 0; i--) {
            if (k == 0) {
                for (int g = b.size() - 1; g >= 1; g--) {
                    a[n - i - 1 + g] = b.get(b.size() - g);
                }
                break;
            }
            j = pa(i - 1);
            int l = k / j + 1;
            if (k % j != 0) {
                a[n - i] = b.get(l);
                b.remove(l);
            } else {
                a[n - i] = b.get(l - 1);
                b.remove(l - 1);
            }
            k = k % j;

        }
        String s = integerFormatString(a);
        return s;
    }

    private int pa(int n) {
        int k = 1;
        if (n == 0) {
            return 1;
        }
        for (int i = 1; i <= n; i++) {
            k = k * i;
        }
        return k;
    }

    public static String integerFormatString(int[] a) {
        int len = a.length;
        char[] ch = new char[len];
        for (int i = 0; i < len; i++) {
            switch (a[i]) {
            case 0:
                ch[i] = '0';
                break;
            case 1:
                ch[i] = '1';
                break;
            case 2:
                ch[i] = '2';
                break;
            case 3:
                ch[i] = '3';
                break;
            case 4:
                ch[i] = '4';
                break;
            case 5:
                ch[i] = '5';
                break;
            case 6:
                ch[i] = '6';
                break;
            case 7:
                ch[i] = '7';
                break;
            case 8:
                ch[i] = '8';
                break;
            case 9:
                ch[i] = '9';
                break;
            default:
                break;
            }
        }
        String str = new String(ch);
        return str;
    }
}