[serpent](https://github.com/ethereum/serpent) go bindings.

## Build instructions

```
go get -d github.com/obscuren/serpent-go
cd $GOPATH/src/github.com/obscuren/serpent-go
git submodule init
git sumbodule update
cd serpent && gitcheckout cpp && make && make install
```
