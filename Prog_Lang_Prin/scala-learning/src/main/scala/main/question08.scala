package main

object question08 {
  var tranposeList: List[List[Any]]
  def transpose(lists:List[List[Int]]):Unit = {
    
  }
  def maxAll(lists:List[List[Int]]) :List[Int] = {

  }
  def main(Args:Array[String]):Unit = {
    println(maxAll(List()))
    println(maxAll(List(List())))
    println(maxAll(List(List(1, 2, 3, 4, 8, 9), List(), List(4, 5), List(1, 2, 3, 5, 6, 10, 11))))
    println(maxAll(List(List(3, 4), List(1, 2, 3, 4, 51, 61), List(1, 2, 31, 41, 61, 51))))
    println(maxAll(List(List(1, 2, 3, 40, 5, 6), List(10, 2, 30, 4), List(1, 200), List(0, 0, 0, 0, 0, 0, 0, 0, 9))))
  }
}
