package lecture01_commonfeatures

object LoopWithCondition {
  def main(args: Array[String]): Unit = {
    for(x <- 0 until 5; if x%2==0) {
      println(x)
    }
    println("-------------------")
    var mylist = List(1,3,5,7)
    for(m <- mylist; if m >= 3 ) {
      println(m)
    }
  }
}
