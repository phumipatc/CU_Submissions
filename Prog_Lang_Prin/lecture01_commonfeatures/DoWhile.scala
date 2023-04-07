package lecture01_commonfeatures

object DoWhile {
  def main(args: Array[String]): Unit = {
    var x =0
    do{
      x += 1    //x++, ++x are NOT allowed in Scala
      println(x)
    } while(x<0)
  }
}
