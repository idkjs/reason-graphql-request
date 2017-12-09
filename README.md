# Basic Reason Template

Hello! This project allows you to quickly get started with Reason and BuckleScript. If you wanted a more sophisticated version, try the `react` template (`bsb -theme react -init .`).

# Build
```
npm run build
```

# Build + Watch

```
npm run watch
```

# test the script
```sh
node src/demo.bs.js
```

## Original Js Script

```js
original js example convertered to reason

const { request } = require('graphql-request')

const query = `{
  Movie(title: "Inception") {
    releaseDate
    actors {
      name
    }
  }
}`
  
request('https://api.graph.cool/simple/v1/movies', query).then(data => console.log(data))
```

