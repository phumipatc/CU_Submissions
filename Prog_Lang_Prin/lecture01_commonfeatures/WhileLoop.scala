package lecture01_commonfeatures

object WhileLoop {
  def main(args: Array[String]): Unit = {
    var x =0
    while(x<10){
      x += 1    //x++, ++x are NOT allowed in Scala
      println(x)
    }
  }
}
