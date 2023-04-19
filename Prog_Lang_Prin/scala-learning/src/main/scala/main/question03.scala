package main

object question03 {
  def findElement(x:Any, l2:List[Any]):Boolean = {
    if(l2.isEmpty)
      return false
    return (x == l2.head) || findElement(x,l2.tail)
  }
  def subList(l1:List[Any], l2:List[Any]):Boolean = {
    if(l1.isEmpty)
      return true
    return findElement(l1.head,l2) && subList(l1.tail,l2)
  }
  def main(args:Array[String]):Unit = {
    var l1 = List(0,1,2,3)
    var l2 = List(0,1,2,3,4,5,6,7,8,9)
    var l3 = List()
    var l4 = List(0,1,2,4)
    var l5 = List(0,1,2,4,5)
    if(subList(l4, l5))
      println("True")
    else
      println("False")
  }
}
