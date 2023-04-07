package lecture01_commonfeatures

object ForLoop {
  def main(args: Array[String]): Unit = {
    for(x <- 0.until(10)) { //step by 1 in each iteration
      println(x)   //print 0 to 9
    }

    for(i <- 1 .to(10)){
      println(i)
    }
  }
}
