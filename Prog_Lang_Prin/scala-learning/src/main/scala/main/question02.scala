package main
object question02 {
  def process(x:Int, list:List[Int]):List[Int] = {
    if(list.isEmpty || list.head >= x)
      return x::list
    return list.head::process(x,list.tail)
  }
  def insertInOrder(x:Int, list:List[Int]):List[Int] = {
    return process(x,list)
  }

  def main(args: Array[String]): Unit = {
    var l = List(0, 1, 2, 3, 4, 6, 7, 8, 9)
    println(insertInOrder(5,l))
  }
}
