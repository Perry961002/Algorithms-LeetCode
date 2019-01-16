public class Solution {
    public List<Interval> merge(List<Interval> intervals) {
        List<Interval> result = new ArrayList<Interval>();
        if(intervals == null || intervals.size()==0)
            return result;
        Collections.sort(intervals,new IntervalComparator());
        Interval prev = intervals.get(0);
        for(int i=1;i<intervals.size();i++){
            Interval curr = intervals.get(i);
            if(prev.end>=curr.start){
                Interval temp =new Interval(prev.start,Math.max(prev.end,curr.end));
                prev = temp;
            }else{
                result.add(prev);
                prev = curr;
            }
        }
        result.add(prev);
        return result;
    }
 }
    class IntervalComparator implements Comparator<Interval>{
        public int compare(Interval s1,Interval s2){
            return s1.start-s2.start;
        }
    }