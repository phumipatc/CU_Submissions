package main

object question07 {
  def myMap(f:Int => Int) (list:List[Int]) :List[Int] = {
    if(list.isEmpty)
      return list
    return f(list.head)::myMap(f)(list.tail)
  }
  def square(x:Int) = x*x
  def main(Args:Array[String]):Unit = {
    println(myMap(x => x*2)(List(1,2,3,4,5)))
    println(myMap(square)(List(1,2,3,4,5)))
  }
}
