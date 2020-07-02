pipeline {
	agent any

	options {
		buildDiscarder(logRotator(numToKeepStr: '10'))
	}

	parameters {
		booleanParam name: 'RUN_ANALYSIS', defaultValue: true, description: 'Run Static Code Analysis?'
	}

	stages {
        stage('Build') {
            steps {
		sh "make"
            }
        }

        stage('Analyse') {
            when {
                environment name: 'RUN_ANALYSIS', value: 'true'
            }
            steps {
		sh "coderrect make clean race"	
            }
        }
	}
}
