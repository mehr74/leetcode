use std::cmp::Ordering;
use std::collections::BinaryHeap;

#[derive(Copy, Clone, Eq, PartialEq)]
struct Dist {
    dist: i32,
    val: i32
}

impl Ord for Dist {
    fn cmp(&self, other: &Self) -> Ordering {
        self.dist.cmp(&other.dist)
            .then_with(|| self.val.cmp(&other.val))
    }
}

impl PartialOrd for Dist {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

struct Solution {
}

impl Solution {
    pub fn find_closest_elements(arr: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        let mut heap = BinaryHeap::new();
        let mut res = Vec::new();
        for entry in arr {
            heap.push(Dist{ dist: (entry - x).abs(), val: entry });

            if (heap.len() as i32) > k {
                heap.pop();
            }
        }

        while let Some(Dist{dist: _, val}) = heap.pop() {
            res.push(val)
        }
        res.sort();
        
        return res;
    }
}

fn main() {
    let mut vec = Vec::new();
    vec.push(1);
    vec.push(2);
    vec.push(3);
    vec.push(4);
    vec.push(5);

    Solution::find_closest_elements(vec, 4, 3);
}
