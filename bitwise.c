#include <stdlib.h>


bin binMSBi(bin x) {
  bin r;
  int i;
  for (i = 0; i < BIN_BITS; i++)
    if (x.bits[i])
      r = binIncrement(binNew(i));
  return r;
}
bin binMSB(bin x) {
  if (binEQZero(x))
    return binNew(0);
  return binShiftL(binNew(1), binDecrement(binMSBi(x)));
}


bin binNOT(bin x) {
  bin r = binNew(0);
  int i;
  for (i = 0; i < BIN_BITS; i++) {
    r.bits[i] = !x.bits[i];
  }
  return r;
}


bin binShiftL(bin x, bin y) {
  return binMultiply(x, binPow(binNew(2), y));
}

bin binShiftL1(bin x) {
  return binShiftL(x, binNew(1));
}

bin binShiftOutZerosL(bin x) {
  return binShiftL(x, binSubtract(binNew(BIN_BITS), binMSBi(x)));
}

bin binShiftR(bin x, bin y) {
  if (binEQZero(y))
    return x;

  bin r = binNew(0);
  int i;
  for (i = BIN_BITS-1; i > 0; i--)
    r.bits[i-1] = x.bits[i];

  return binShiftR(r, binDecrement(y));
}

bin binShiftR1(bin x) {
  return binShiftR(x, binNew(1));
}

bin binShiftOutZerosR(bin x) {
  if (binEQZero(x))
    return binNew(0);
  return binShiftR(x, binDecrement(binMSBi(x)));
}


bin binAND(bin x, bin y) {
  int i;
  bin r = binNew(0);
  for (i = 0; i < BIN_BITS; i++)
    if (x.bits[i] && y.bits[i])
      r.bits[i] = 1;
  return r;
}

bin binOR(bin x, bin y) {
  int i;
  bin r = binNew(0);
  for (i = 0; i < BIN_BITS; i++)
    if (x.bits[i] || y.bits[i])
      r.bits[i] = 1;
  return r;
}

bin binXOR(bin x, bin y) {
  int i;
  bin r = binNew(0);
  for (i = 0; i < BIN_BITS; i++)
    if ((x.bits[i] || y.bits[i])
    && !(x.bits[i] && y.bits[i]))
      r.bits[i] = 1;
  return r;
}
