# uname2


Artwork by [i5ting](http://www.github.com/i5ting/).

[![Deps](https://david-dm.org/i5ting/uname2.svg)](https://david-dm.org/i5ting/uname2) 
[![npm](https://img.shields.io/npm/v/uname2.svg)](https://www.npmjs.com/package/uname2)
[![GitHub license](https://img.shields.io/badge/license-MIT-blue.svg)](https://raw.githubusercontent.com/i5ting/uname2/master/LICENSE.md)
[![npm](https://img.shields.io/npm/dt/uname2.svg)](https://www.npmjs.com/package/uname2)


## Install

    npm install --save uname2

## Usage

```
var uname2 = require('uname2')

console.dir(uname2);

console.log(uname2.sysname());
console.log(uname2.nodename());
console.log(uname2.release());
console.log(uname2.version());
console.log(uname2.machine());
```

## Test

```
npm start && node sys.js
```
## 调试

```
env V=1 node-gyp rebuild
```


## ld: library not found for -lgcc_s.10.5

Per [this issue](https://github.com/nodejs/node-gyp/issues/773), I was able to resolve this by entering this temp command:

```
cd /usr/local/lib 
sudo ln -s ../../lib/libSystem.B.dylib libgcc_s.10.5.dylib 
```

## Contributing

1. Fork it
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create new Pull Request

## 版本历史

- v1.0.0 初始化版本

## 欢迎fork和反馈

- write by `i5ting` i5ting@126.com

如有建议或意见，请在issue提问或邮件

## License

this repo is released under the [MIT
License](http://www.opensource.org/licenses/MIT).
