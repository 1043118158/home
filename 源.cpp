#include<vector>
#include<stack>
#include<iostream>
using namespace std;



////插入排序
////插入排序是稳定的，双for时间复杂度为n^2;
//void insertsort(vector<int>& arr)
//{
//    //假设第一个元素是有序的
//    int size = arr.size();
//    for (int i = 1; i < size; ++i)
//    {
//        int end = i - 1;
//        int num = arr[i];
//        while (end >= 0 && arr[end] > num)
//        {
//            arr[end + 1] = arr[end];
//            end--;
//        }
//        swap(arr[end + 1], num);
//        // arr[end+1]=num;
//    }
//}
////希尔排序
////希尔排序是不稳定的，时间复杂度为nlogn
////一遍找元素n，一遍找位置logn
//void shellsort(vector<int>& arr)
//{
//    int size = arr.size();
//    int gap = size;
//    while (gap > 1) {
//        gap = gap / 2;
//        for (int i = gap; i < size; ++i)
//        {
//            int num = arr[i];
//            int end = i - gap;
//            while (end >= 0 && arr[end] > num)
//            {
//                arr[end + gap] = arr[end];
//                end -= gap;
//            }
//            swap(arr[end += gap], num);
//        }
//    }
//}
////选择排序
////选择排序是不稳定的 双for时间复杂度为n^2
//void selectsort(vector<int>& arr)
//{
//    int size = arr.size();
//    for (int i = 0; i < size; ++i)
//    {
//        int min = i;
//        for (int j = i; j < size; ++j)
//        {
//            if (arr[min] > arr[j])
//                min = j;
//        }
//        swap(arr[i], arr[min]);
//    }
//}
//
//
////冒泡排序
////是稳定的，双for时间复杂度为n^2
//void bublesort(vector<int>& arr)
//{
//    int size = arr.size();
//    for (int i = size - 1; i >= 0; --i)
//    {
//        for (int j = 0; j < i; ++j)
//        {
//            if (arr[j] > arr[j + 1])
//                swap(arr[j], arr[j + 1]);
//        }
//    }
//}
//
//
//
//
//
////堆排序
////不是稳定的，时间复杂度为nlogn;
////查找元素n，查找位置logn
//void shiftdown(vector<int>& arr, int size, int i)
//{
//    //向下调整
//    int parent = i;
//    int child = 2 * parent + 1;
//    while (child < size) {
//        while (child + 1 < size && arr[child] < arr[child + 1])
//            child += 1;
//        if (arr[child] > arr[parent])
//        {
//            swap(arr[child], arr[parent]);
//            parent = child;
//        }
//        child = child * 2 + 1;
//    }
//}
//void bulidheap(vector<int>& arr, int size)
//{
//    //从最后一个非叶子节点开始向下调整
//    for (int i = (size / 2) - 1; i >= 0; i--) {
//        shiftdown(arr, size, i);
//    }
//}
//void heapsort(vector<int>& arr)
//{
//    int size = arr.size();
//    bulidheap(arr, size); //建堆
//    for (int i = size - 1; i >= 0; --i)//逐个堆排序
//    {
//        swap(arr[i], arr[0]);
//        shiftdown(arr, i, 0);
//    }
//}
//
//
////归并排序
////是稳定的，时间复杂度为nlogn
////查找元素为n，查找位置为logn
//void merge(vector<int>& arr, int begin, int mid, int end, vector<int>& tmp)
//{
//    int begin1 = begin;
//    int end1 = mid;
//    int begin2 = mid + 1;
//    int end2 = end;
//
//    int idx = begin;
//    while (begin1 <= end1 && begin2 <= end2)
//    {
//        if (arr[begin1] <= arr[begin2])
//            tmp[idx++] = arr[begin1++];
//        else if (arr[begin1] > arr[begin2])
//            tmp[idx++] = arr[begin2++];
//    }
//    //将还没有插进去的元素直接插入tmp
//    while (begin1 <= end1)
//        tmp[idx++] = arr[begin1++];
//    while (begin2 <= end2)
//        tmp[idx++] = arr[begin2++];
//
//    //最后应该将tmp上的元素都存储在arr上
//    int m = begin;
//    while (m <= end)
//    {
//        arr[m] = tmp[m];
//        m++;
//    }
//
//
//
//
//}
//void _merge(vector<int>& arr, int begin, int end, vector<int>& tmp)
//{
//    if (begin >= end)
//        return;
//    int mid = ((end - begin) / 2 + begin);
//    _merge(arr, begin, mid, tmp);
//    _merge(arr, mid + 1, end, tmp);
//
//    //合并子序列
//    merge(arr, begin, mid, end, tmp);
//
//}
//void mergesort(vector<int>& arr)
//{
//
//    int size = arr.size();
//    vector<int>tmp(size);
//    _merge(arr, 0, size - 1, tmp);
//}
//
//
//
//
//
//
////快速排序
////快排的优化：
////选择基准值时可以采用三数取中法来选择基准值
////在子区间比较小时改用插入排序。
//
////三数取中法获取基准值；
//
////快排不是稳定的，时间复杂度是nlogn
////查找元素n，寻找位置logn
//int partion(vector<int>& arr, int begin, int end)
//{
//    //挖坑法
//    int key = arr[begin];
//    while (begin < end)
//    {
//        while (begin < end && arr[end] >= key)
//            end--;
//        arr[begin] = arr[end];
//        while (begin < end && arr[begin] <= key)
//            begin++;
//        arr[end] = arr[begin];
//    }
//    swap(arr[begin], key);
//    return begin;
//}
//
//int partion2(vector<int>& arr, int begin, int end)
//{
//    //hoare法
//    int start = begin;
//    int key = arr[begin];
//    while (begin < end)
//    {
//        while (begin < end && arr[end] >= key)
//            end--;
//        while (begin < end && arr[begin] <= key)
//            begin++;
//        swap(arr[begin], arr[end]);
//    }
//    swap(arr[begin], arr[start]);
//    return begin;
//
//}
//void quicksort(vector<int>& arr, int begin, int end)
//{
//    //递归排序
//    if (begin >= end)
//        return;
//    int div = partion2(arr, begin, end);
//    quicksort(arr, begin, div - 1);
//    quicksort(arr, div + 1, end);
//
//
//}
//void quicksort2(vector<int>& arr, int begin, int end)
//{
//    //非递归快排
//    stack<int>st;
//    st.push(end);
//    st.push(begin);
//    while (!st.empty())
//    {
//        int start = st.top();
//        st.pop();
//        int finish = st.top();
//        st.pop();
//        int div = partion(arr, start, finish);
//        if ((div - 1) > start) {
//            st.push(div - 1);
//            st.push(begin);
//        }
//        if ((div + 1) < finish)
//        {
//            st.push(end);
//            st.push(div + 1);
//
//        }
//    }
//}



//寻找逆序对
//void Merge(vector<int>& data, int begin, int mid, int end, vector<int>& tmp, int& result)
//{
//    int begin1 = begin;
//    int end1 = mid;
//    int begin2 = mid + 1;
//    int end2 = end;
//
//    int idx = begin;
//    while (begin1 <= end1 && begin2 <= end2) {
//        if (data[begin1] <= data[begin2])
//        {
//            tmp[idx++] = data[begin1++];
//        }
//        else
//        {
//            tmp[idx++] = data[begin2++];
//            result += (mid - begin1 + 1);
//
//        }
//
//    }
//
//    while (begin1 <= end1)
//        tmp[idx++] = data[begin1++];
//    while (begin2 <= end2)
//        tmp[idx++] = data[begin2++];
//
//    while (begin <= end)
//    {
//        data[begin] = tmp[begin];
//        begin++;
//    }
//}
//void Merge1(vector<int>& data, int begin, int end, vector<int>& tmp, int& result)
//{
//    if (begin >= end)
//        return;
//    int mid = (begin + (end - begin) / 2);
//    Merge1(data, begin, mid, tmp, result);
//    Merge1(data, mid + 1, end, tmp, result);
//
//    Merge(data, begin, mid, end, tmp, result);
//
//}
//int InversePairs(vector<int>& data) {
//    int result = 0;
//    vector<int>tmp(data.size());
//    Merge1(data, 0, data.size() - 1, tmp, result);
//    return result;
//}
//
//
//int main()
//{
//
//    int n;
//    int num;
//    while (cin >> n) {
//        vector<int>arr(n);
//        for (int i = 0; i < n; ++i)
//        {
//            cin >> num;
//            arr[i] = num;
//        }
//        int begin = 0;
//        int end = arr.size() - 1;
//        //quicksort2(arr,begin,end);
//       int ret= InversePairs(arr);
//       cout << ret << endl;
//        
//        for (auto& e : arr)
//        {
//            cout << e << " ";
//        }
//        cout << endl;
//    }
//
//
//    return 0;
//}