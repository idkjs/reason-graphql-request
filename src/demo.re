[@bs.module "graphql-request"]
external request : (~x:string, ~y:string) => Js.Promise.t(Js.Json.t) = "request";

let uri = "https://api.graph.cool/simple/v1/movies";

/* [@bs.module "graphql-tag"] external gql : string => string = "gql"; */

let query = [%raw {|
    `{
        Movie(title: "Inception") {
          releaseDate
          actors {
            name
          }
        }
      }`
      |}];

request(~x=uri, ~y=query)
|> Js.Promise.then_(
  data => Js.Promise.resolve(Js.log(data))
);
