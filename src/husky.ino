int huskyread() {
  huskylens.request();
  HUSKYLENSResult result = huskylens.read();
  id = result.ID;

  return id;
}
