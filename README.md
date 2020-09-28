## How to test tdelete's returning a dangling address bug ?

Run the command:
```
make
```



The console output

```
Testing glibc's implementation of tdelete for a returning dangling address bug

  allocate 0x7fd9f70b0324
  allocate 0x7fd9f70b0388
  allocate 0x7fd9f70b03ec
  allocate 0x7fd9f70b0450
  free 0x7fd9f70b0324
  tdelete returns 0x7fd9f70b0388
  free 0x7fd9f70b0388
  tdelete returns 0x7fd9f70b03ec
  free 0x7fd9f70b03ec
  tdelete returns 0x7fd9f70b03ec <- dangling pointer
  free 0x7fd9f70b0450
  tdelete returns 0x7fd9f70b0450 <- dangling pointer

Testing musl libc's implementation of tdelete for a returning dangling address bug

  allocate 0x7f2ecf539324
  allocate 0x7f2ecf539388
  allocate 0x7f2ecf5393ec
  allocate 0x7f2ecf539450
  free 0x7f2ecf539324
  tdelete returns 0x7f2ecf539388
  free 0x7f2ecf539388
  tdelete returns 0x7f2ecf5393ec
  free 0x7f2ecf5393ec            
  tdelete returns 0x7f2ecf5393ec <- dangling pointer
  free 0x7f2ecf539450
  tdelete returns 0x7f2ecf539450 <- dangling pointer
```
