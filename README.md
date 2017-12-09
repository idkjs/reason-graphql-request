# reason-graphql-request bindings

## Takeaways

- Use `Js.Promise.t(Js.Json.t)` to wait for the Json response. Js.Json.t is the type we set the response to. Pass it to Js.Promise so reason knows to wait for it.


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
- see working example: https://runkit.com/593130bdfad7120012472003/593130bdfad7120012472004

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

