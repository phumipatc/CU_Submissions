package main

object question08 {
  def max(list1:List[Int], list2: List[Int] ): List[Int] = {
    if(list1.isEmpty)
      return list2
    if(list2.isEmpty)
      return list1
    if(list1.head > list2.head)
      return list1.head::max(list1.tail, list2.tail)
    else
      return list2.head::max(list1.tail, list2.tail)
  }
  def maxAll(lists:List[List[Int]]) :List[Int] = {
    if(lists.isEmpty)
      return List()
    max(lists.head, maxAll(lists.tail))

  }
  def main(Args:Array[String]):Unit = {
    println(maxAll(List()))
    println(maxAll(List(List())))
    println(maxAll(List(List(1, 2, 3, 4, 8, 9), List(), List(4, 5), List(1, 2, 3, 5, 6, 10, 11))))
    println(maxAll(List(List(3, 4), List(1, 2, 3, 4, 51, 61), List(1, 2, 31, 41, 61, 51))))
    println(maxAll(List(List(1, 2, 3, 40, 5, 6), List(10, 2, 30, 4), List(1, 200), List(0, 0, 0, 0, 0, 0, 0, 0, 9))))
  }
}
