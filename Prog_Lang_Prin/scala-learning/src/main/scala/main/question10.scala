package main

object Question10 {
  def alternate(f1: (Int,Int) => Int, f2: (Int,Int) => Int, list:List[Int]):Int = {
    if(list.length == 0)
      return 0
    if(list.length == 1)
      return list.head
    return alternate(f2,f1, f1(list.head, list.tail.head) :: list.tail.tail)
  }
  def main(args: Array[String]): Unit = {
    var + = (x:Int, y:Int) => x+y
    var - = (x:Int, y:Int) => x-y
    var * = (x: Int, y: Int) => x*y
    println(alternate(+,-,List()))
    println(alternate(+,-,List(55)))
    println(alternate(+,-,List(1,2)))
    println(alternate(+,-,List(1,2,3)))
    println(alternate(+,-,List(1,2,3,4)))
  }
}
