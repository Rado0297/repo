var path = require('path');
var rootPath = path.normalize(__dirname + '/../../')

module.exports = {
    development: {
        rootPath: rootPath,
        db: 'mongodb://localhost/codecompilerusers',
        port: process.env.PORT || 7070
    },
    production: {
        rootPath: rootPath,
        db: 'mongodb:....codecompilerusers',
        port: process.env.PORT || 7070
    }
}
